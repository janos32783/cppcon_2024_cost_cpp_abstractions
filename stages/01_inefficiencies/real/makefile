include ../../common.mk

OBJS = ./Core/Src/main.o \
       ./Core/Src/stm32f0xx_hal_msp.o \
       ./Core/Src/stm32f0xx_it.o \
       ./Core/Src/syscalls.o \
       ./Core/Src/sysmem.o \
       ./Core/Src/system_stm32f0xx.o \
       ./Core/Startup/startup_stm32f030cctx.o \
       ./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal.o \
       ./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_adc.o \
       ./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_adc_ex.o \
       ./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_cortex.o \
       ./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_dma.o \
       ./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_exti.o \
       ./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_flash.o \
       ./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_flash_ex.o \
       ./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_gpio.o \
       ./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_i2c.o \
       ./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_i2c_ex.o \
       ./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_pwr.o \
       ./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_pwr_ex.o \
       ./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_rcc.o \
       ./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_rcc_ex.o \
       ./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_tim.o \
       ./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_tim_ex.o
LINKER_SCRIPT = ../../linker_script.ld
ELF = main.elf
BIN = main.bin

CFLAGS += -ICore/Inc \
          -IDrivers/CMSIS/Include \
		  -IDrivers/CMSIS/Device/ST/STM32F0xx/Include \
          -IDrivers/STM32F0xx_HAL_Driver/Inc \
		  -DUSE_HAL_DRIVER -DSTM32F030xC

all: prog

prog: $(OBJS)
	$(CC) $(LDFLAGS) -o $(ELF) $(OBJS) -T $(LINKER_SCRIPT)
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