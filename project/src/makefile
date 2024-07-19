include common.mk

INCLUDES += -I../hal/STM32F0xx_HAL_Driver/Inc \
            -I../hal/CMSIS/Device/ST/STM32F0xx/Include \
			-I../hal/CMSIS/Include

OBJS = main.o \
       startup.o \
       stm32f0xx_hal_msp.o \
       stm32f0xx_it.o \
       syscalls.o \
       sysmem.o \
       system_stm32f0xx.o \
       ../hal/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_adc_ex.o \
       ../hal/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_adc.o \
       ../hal/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_cortex.o \
       ../hal/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_dma.o \
       ../hal/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_exti.o \
       ../hal/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_flash_ex.o \
       ../hal/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_flash.o \
       ../hal/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_gpio.o \
       ../hal/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_i2c_ex.o \
       ../hal/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_i2c.o \
       ../hal/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_pwr_ex.o \
       ../hal/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_pwr.o \
       ../hal/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_rcc_ex.o \
       ../hal/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_rcc.o \
       ../hal/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_tim_ex.o \
       ../hal/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_tim.o \
       ../hal/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_uart_ex.o \
       ../hal/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_uart.o \
       ../hal/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal.o

CXXFLAGS += -DUSE_HAL_DRIVER -DSTM32F030xC
CFLAGS += -DUSE_HAL_DRIVER -DSTM32F030xC

LINKER_SCRIPT = linker_script.ld
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