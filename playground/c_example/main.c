#include <stdint.h>

uint32_t m_memory [100];

#define ELEM_0 (*((volatile uint32_t*)m_memory[0]))
#define ELEM_1 (*((volatile uint32_t*)m_memory[1]))
#define ELEM_2 (*((volatile uint32_t*)m_memory[2]))
#define ELEM_3 (*((volatile uint32_t*)m_memory[3]))

#define CHOICE_0 ((uint16_t)0x0000)
#define CHOICE_1 ((uint16_t)0x0001)
#define CHOICE_2 ((uint16_t)0x0002)
#define CHOICE_3 ((uint16_t)0x0003)

#define MODE_0 (0x00000000U)
#define MODE_1 (0x00000001U)

#define MASK_0 (0x00000000U)
#define MASK_1 (0x00000001U)

#define IS_CHOICE(X) ((X) < 0xFFFF && (X) >= 0)
#define IS_MODE(X) (((X) == MODE_0) || ((X) == MODE_1))

typedef struct {
    uint32_t choice ;
    uint32_t mode ;
} InitStruct ;

void Init(InitStruct* init_struct) {
    uint32_t temp;

    /* check the values */
    if (!IS_CHOICE(init_struct->choice)) { return; }
    if (!IS_MODE(init_struct->mode)) { return; }

    /* configure the GPIO based on the settings */
    if (init_struct->mode == MODE_0) {
        temp = ELEM_0;
        temp &= ~(MASK_0 << (init_struct->mode * 2u));
        temp |= (MASK_1 << (init_struct->choice * 2u));
        ELEM_0 = temp;

        temp = ELEM_1;
        temp &= ~(MASK_1 << init_struct->choice);
        temp |= (((init_struct->mode & MASK_1) >> 4u) << init_struct->mode);
        ELEM_1 = temp;
    }

    temp = ELEM_1;
    temp &= ~(MASK_1 << (init_struct->choice * 2u));
    temp |= ((init_struct->mode & MASK_1) << (init_struct->choice * 2u));
    ELEM_1 = temp;
}

int main (void) {

    {
        InitStruct init_struct = {0};
        
        init_struct.choice = CHOICE_0;
        init_struct.mode = MODE_1;

        Init(&init_struct) ;
    }

    while (1) {}
}