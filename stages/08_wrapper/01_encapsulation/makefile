NOEXCEPT=1
HAL=1
include ../../common.mk

INCLUDES += -I../../hal/Drivers/STM32F0xx_HAL_Driver/Inc \
            -I../../hal/Drivers/CMSIS/Device/ST/STM32F0xx/Include \
            -I../../hal/Drivers/CMSIS/Include \
            -I../../hal/Core/Inc \
            -I../..

OBJS = main.o \
       ../../hal/Core/Src/stm32f0xx_hal_msp.o \
       ../../hal/Core/Src/stm32f0xx_it.o \
       ../../hal/Core/Src/syscalls.o \
       ../../hal/Core/Src/sysmem.o \
       ../../hal/Core/Src/system_stm32f0xx.o \
       ../../hal/Core/Startup/startup_stm32f030cctx.o \
       ../../hal/Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal.o \
       ../../hal/Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_adc.o \
       ../../hal/Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_adc_ex.o \
       ../../hal/Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_cortex.o \
       ../../hal/Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_dma.o \
       ../../hal/Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_exti.o \
       ../../hal/Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_flash.o \
       ../../hal/Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_flash_ex.o \
       ../../hal/Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_gpio.o \
       ../../hal/Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_i2c.o \
       ../../hal/Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_i2c_ex.o \
       ../../hal/Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_pwr.o \
       ../../hal/Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_pwr_ex.o \
       ../../hal/Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_rcc.o \
       ../../hal/Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_rcc_ex.o \
       ../../hal/Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_tim.o \
       ../../hal/Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_tim_ex.o \
       ../../hal/Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_uart_ex.o \
       ../../hal/Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_uart.o

LINKER_SCRIPT = ../../hal/STM32F030CCTX_FLASH.ld
ELF = main.elf
BIN = main.bin

all: prog

prog: $(OBJS)
	$(CXX) $(LDFLAGS) -o $(ELF) $(OBJS) -T $(LINKER_SCRIPT)
	$(OBJCOPY) -O binary $(ELF) $(BIN)

objdump:
	$(OBJDUMP) -h -S $(ELF)

size:
	$(SIZE) $(ELF)

flash:
	$(STFLASH) write $(BIN) $(FLASHSTART)

reset:
	$(STFLASH) reset

clean:
	@for obj in $(OBJS); do if [ -f "$$obj" ]; then rm $$obj; fi; done
	@rm -rf $(ELF)
	@rm -rf $(BIN)