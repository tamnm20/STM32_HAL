################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/ESP8266_HAL.c \
../Core/UartRingbuffer_multi.c 

OBJS += \
./Core/ESP8266_HAL.o \
./Core/UartRingbuffer_multi.o 

C_DEPS += \
./Core/ESP8266_HAL.d \
./Core/UartRingbuffer_multi.d 


# Each subdirectory must supply rules for building sources it contributes
Core/%.o Core/%.su Core/%.cyclo: ../Core/%.c Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F446xx -DDEBUG -c -I../Drivers/CMSIS/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core

clean-Core:
	-$(RM) ./Core/ESP8266_HAL.cyclo ./Core/ESP8266_HAL.d ./Core/ESP8266_HAL.o ./Core/ESP8266_HAL.su ./Core/UartRingbuffer_multi.cyclo ./Core/UartRingbuffer_multi.d ./Core/UartRingbuffer_multi.o ./Core/UartRingbuffer_multi.su

.PHONY: clean-Core

