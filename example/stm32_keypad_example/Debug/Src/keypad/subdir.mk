################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/keypad/Keypad.c \
../Src/keypad/config.c 

OBJS += \
./Src/keypad/Keypad.o \
./Src/keypad/config.o 

C_DEPS += \
./Src/keypad/Keypad.d \
./Src/keypad/config.d 


# Each subdirectory must supply rules for building sources it contributes
Src/keypad/%.o: ../Src/keypad/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -mfloat-abi=soft '-D__weak=__attribute__((weak))' '-D__packed="__attribute__((__packed__))"' -DUSE_HAL_DRIVER -DSTM32F103xB -I"/Users/neptunex/Documents/st_workspace/stm32_keypad_example/Inc" -I"/Users/neptunex/Documents/st_workspace/stm32_keypad_example/Drivers/STM32F1xx_HAL_Driver/Inc" -I"/Users/neptunex/Documents/st_workspace/stm32_keypad_example/Drivers/STM32F1xx_HAL_Driver/Inc/Legacy" -I"/Users/neptunex/Documents/st_workspace/stm32_keypad_example/Drivers/CMSIS/Device/ST/STM32F1xx/Include" -I"/Users/neptunex/Documents/st_workspace/stm32_keypad_example/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


