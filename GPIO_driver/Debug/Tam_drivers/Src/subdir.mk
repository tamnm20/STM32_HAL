################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Tam_drivers/Src/stm32_gpio.c 

OBJS += \
./Tam_drivers/Src/stm32_gpio.o 

C_DEPS += \
./Tam_drivers/Src/stm32_gpio.d 


# Each subdirectory must supply rules for building sources it contributes
Tam_drivers/Src/%.o Tam_drivers/Src/%.su Tam_drivers/Src/%.cyclo: ../Tam_drivers/Src/%.c Tam_drivers/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I"C:/Users/TAMRD/Documents/STM32_HAL/GPIO_driver/Tam_drivers/Inc" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Tam_drivers-2f-Src

clean-Tam_drivers-2f-Src:
	-$(RM) ./Tam_drivers/Src/stm32_gpio.cyclo ./Tam_drivers/Src/stm32_gpio.d ./Tam_drivers/Src/stm32_gpio.o ./Tam_drivers/Src/stm32_gpio.su

.PHONY: clean-Tam_drivers-2f-Src

