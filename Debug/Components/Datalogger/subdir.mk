################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Components/Datalogger/API_datalogger.c 

OBJS += \
./Components/Datalogger/API_datalogger.o 

C_DEPS += \
./Components/Datalogger/API_datalogger.d 


# Each subdirectory must supply rules for building sources it contributes
Components/Datalogger/%.o: ../Components/Datalogger/%.c Components/Datalogger/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Components-2f-Datalogger

clean-Components-2f-Datalogger:
	-$(RM) ./Components/Datalogger/API_datalogger.d ./Components/Datalogger/API_datalogger.o

.PHONY: clean-Components-2f-Datalogger

