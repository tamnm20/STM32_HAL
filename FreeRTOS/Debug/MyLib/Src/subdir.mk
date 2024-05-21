################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MyLib/Src/adc.c \
../MyLib/Src/uart.c 

OBJS += \
./MyLib/Src/adc.o \
./MyLib/Src/uart.o 

C_DEPS += \
./MyLib/Src/adc.d \
./MyLib/Src/uart.d 


# Each subdirectory must supply rules for building sources it contributes
MyLib/Src/%.o MyLib/Src/%.su MyLib/Src/%.cyclo: ../MyLib/Src/%.c MyLib/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM3 -I"C:/Users/TAMRD/Documents/STM32_HAL/FreeRTOS/MyLib/Inc" -O0 -ffunction-sections -fdata-sections -Wall -specs=nosys.specs -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-MyLib-2f-Src

clean-MyLib-2f-Src:
	-$(RM) ./MyLib/Src/adc.cyclo ./MyLib/Src/adc.d ./MyLib/Src/adc.o ./MyLib/Src/adc.su ./MyLib/Src/uart.cyclo ./MyLib/Src/uart.d ./MyLib/Src/uart.o ./MyLib/Src/uart.su

.PHONY: clean-MyLib-2f-Src

