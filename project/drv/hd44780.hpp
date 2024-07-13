#pragma once

#include "intf/delay.hpp"
#include "intf/gpio.hpp"

#include <cstring>

namespace drv {

/**
 *  display layout
 * 
 *  +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
 *  |00|01|02|03|04|05|06|07|08|09|0a|0b|0c|0d|0e|0f|
 *  +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
 *  |40|41|42|43|44|45|46|47|48|49|4a|4b|4c|4d|4e|4f|
 *  +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
*/

template <intf::GPIO TGpio, intf::Delay TDelay>
class CHd44780 {
private:
    TGpio* m_pwr { nullptr };   /* pin to control whether the LCD is powered on or now (can be null) */
    TGpio* m_rs  { nullptr };
    TGpio* m_rw  { nullptr };
    TGpio* m_en  { nullptr };
    TGpio* m_d0  { nullptr };
    TGpio* m_d1  { nullptr };
    TGpio* m_d2  { nullptr };
    TGpio* m_d3  { nullptr };
    TGpio* m_d4  { nullptr };
    TGpio* m_d5  { nullptr };
    TGpio* m_d6  { nullptr };
    TGpio* m_d7  { nullptr };
    TDelay* m_delay { nullptr };

    static constexpr std::uint8_t line_0_addr { 0x00 };
    static constexpr std::uint8_t line_1_addr { 0x40 };

    static constexpr std::uint8_t cmd_clear_display  { 0b00000001 };
    static constexpr std::uint8_t cmd_return_home    { 0b00000010 };
    static constexpr std::uint8_t cmd_entry_mode_set { 0b00000110 };
    static constexpr std::uint8_t cmd_display_on     { 0b00001100 };
    static constexpr std::uint8_t cmd_display_off    { 0b00001000 };
    static constexpr std::uint8_t cmd_function_set   { 0b00111000 };

    bool send_command (std::uint8_t cmd) {
        m_rs->write(false);                    /* instruction mode  */
        m_rw->write(false);                    /* set to write mode */
        m_d0->write(cmd & 0b00000001);         /* set data bit 0    */
        m_d1->write(cmd & 0b00000010);         /* set data bit 1    */
        m_d2->write(cmd & 0b00000100);         /* set data bit 2    */
        m_d3->write(cmd & 0b00001000);         /* set data bit 3    */
        m_d4->write(cmd & 0b00010000);         /* set data bit 4    */
        m_d5->write(cmd & 0b00100000);         /* set data bit 5    */
        m_d6->write(cmd & 0b01000000);         /* set data bit 6    */
        m_d7->write(cmd & 0b10000000);         /* set data bit 7    */
        m_en->write(true);                     /* pull enable high  */
        m_delay->delay_us(10);
        m_en->write(false);                    /* pull enable low -> trigger function */
        /* wait for busy flag */
        //m_dx[7]->reset();
        //m_dx[7]->set_mode_input();
        //m_rs->write(false);
        //m_rw->write(true);
        //bool busy_flag = false;
        //while (true) {
        //    m_dx[7]->get_level();
        //}
        return true;
    }
    bool send_data (std::uint8_t data) {
        m_rs->write(true);                      /* data mode         */
        m_rw->write(false);                     /* set to write mode */
        m_d0->write(data & 0b00000001);         /* set data bit 0    */
        m_d1->write(data & 0b00000010);         /* set data bit 1    */
        m_d2->write(data & 0b00000100);         /* set data bit 2    */
        m_d3->write(data & 0b00001000);         /* set data bit 3    */
        m_d4->write(data & 0b00010000);         /* set data bit 4    */
        m_d5->write(data & 0b00100000);         /* set data bit 5    */
        m_d6->write(data & 0b01000000);         /* set data bit 6    */
        m_d7->write(data & 0b10000000);         /* set data bit 7    */
        m_en->write(true);                      /* pull enable high  */
        m_delay->delay_us(10);
        m_en->write(false);                     /* pull enable low -> trigger function */
        return true;
    }

public:
    CHd44780 (osal::IDelay* delay) : m_delay(delay) {}
    ~CHd44780() = default;
    
    bool turn_on () {
        if (m_pwr != nullptr) {
            m_pwr->write(true);                   /* turn on the LCD */
        }
        m_delay->delay_ms(100);                       /* wait for more than 40ms */
        send_command(cmd_function_set);               /* init step 1 */
        m_delay->delay_ms(10);                        /* wait for more than 4.1ms */
        send_command(cmd_function_set);               /* init step 2 */
        m_delay->delay_us(200);                       /* wait for more than 100us */
        send_command(cmd_function_set);               /* init step 3 */
        m_delay->delay_us(200);                       /* execution time : 37us */
        
        send_command(cmd_function_set);               /* set function */
        m_delay->delay_us(80);                        /* execution time : 37us */
        send_command(cmd_display_off);                /* display off */
        m_delay->delay_us(80);                        /* execution time : 37us */
        send_command(cmd_clear_display);              /* clear display */
        m_delay->delay_ms(4);                         /* execution time : 1.52ms */
        send_command(cmd_entry_mode_set);             /* set entry mode */
        m_delay->delay_us(80);                        /* execution time : 37us */
        send_command(cmd_display_on);                 /* display on */
        m_delay->delay_us(80);                        /* execution time : 37us */
        return true;
    }
    bool turn_off () {
        send_command(cmd_display_off);                /* display off */
        m_delay->delay_us(80);                        /* execution time : 37us */
        if (m_pwr != nullptr) {
            m_pwr->write(false);                  /* turn on the LCD */
        }
        return true;
    }
    bool clear_display () {
        send_command(cmd_clear_display);              /* clear display */
        m_delay->delay_ms(2);                         /* execution time : 1.52ms */
        return true;
    }
    bool set_display (const char* str, int str_len) {
        send_command(cmd_clear_display);              /* clear display */
        m_delay->delay_ms(2);                         /* execution time : 1.52ms */
        send_command(cmd_return_home);                /* home cursor */
        m_delay->delay_ms(2);                         /* execution time : 1.52ms */
        for (int i = 0; (i < str_len) || (i < display_length); ++i) {
            if (str[i] == 0) break;
            send_data(static_cast<uint8_t>(str[i]));
            m_delay->delay_us(80);                        /* execution time : 37us */
        }
        return true;
    }

    void set_rs (hal::IGpio* rs) {
        m_rs = rs;
        m_rs->reset();
        m_rs->set_mode_output();
        m_rs->write(false);
    }
    void set_rw (hal::IGpio* rw) {
        m_rw = rw;
        m_rw->reset();
        m_rw->set_mode_output();
        m_rw->write(false);
    }
    void set_en (hal::IGpio* en) {
        m_en = en;
        //m_en->reset();
        m_en->set_mode_output();
        m_en->write(true);
    }
    void set_d0 (hal::IGpio* d0) {
        m_d0 = d0;
        m_d0->reset();
        m_d0->set_mode_output();
        m_d0->write(false);
    }
    void set_d1 (hal::IGpio* d1) {
        m_d1 = d1;
        m_d1->reset();
        m_d1->set_mode_output();
        m_d1->write(false);
    }
    void set_d2 (hal::IGpio* d2) {
        m_d2 = d2;
        m_d2->reset();
        m_d2->set_mode_output();
        m_d2->write(false);
    }
    void set_d3 (hal::IGpio* d3) {
        m_d3 = d3;
        m_d3->reset();
        m_d3->set_mode_output();
        m_d3->write(false);
    }
    void set_d4 (hal::IGpio* d4) {
        m_d4 = d4;
        m_d4->reset();
        m_d4->set_mode_output();
        m_d4->write(false);
    }
    void set_d5 (hal::IGpio* d5) {
        m_d5 = d5;
        m_d5->reset();
        m_d5->set_mode_output();
        m_d5->write(false);
    }
    void set_d6 (hal::IGpio* d6) {
        m_d6 = d6;
        m_d6->reset();
        m_d6->set_mode_output();
        m_d6->write(false);
    }
    void set_d7 (hal::IGpio* d7) {
        m_d7 = d7;
        m_d7->reset();
        m_d7->set_mode_output();
        m_d7->write(false);
    }

    void set_pwr (hal::IGpio* pwr) {
        m_pwr = pwr;
        m_pwr->reset();
        m_pwr->set_mode_output();
        m_pwr->write(false);
    }

    static constexpr std::uint8_t display_length = 32;
};

} /* namespace drv */