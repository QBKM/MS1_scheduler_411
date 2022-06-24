################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Components/Sensors/API_sensors.c \
../Components/Sensors/bmp280.c \
../Components/Sensors/mpu6050.c 

OBJS += \
./Components/Sensors/API_sensors.o \
./Components/Sensors/bmp280.o \
./Components/Sensors/mpu6050.o 

C_DEPS += \
./Components/Sensors/API_sensors.d \
./Components/Sensors/bmp280.d \
./Components/Sensors/mpu6050.d 


# Each subdirectory must supply rules for building sources it contributes
Components/Sensors/%.o: ../Components/Sensors/%.c Components/Sensors/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I"C:/Users/Quent/Desktop/Workspaces/STM_Workspace/MS1_Workspace/MS1_scheduler_411/Configuration" -I"C:/Users/Quent/Desktop/Workspaces/STM_Workspace/MS1_Workspace/MS1_scheduler_411/Components/Application/inc" -I"C:/Users/Quent/Desktop/Workspaces/STM_Workspace/MS1_Workspace/MS1_scheduler_411/Components/Audio/inc" -I"C:/Users/Quent/Desktop/Workspaces/STM_Workspace/MS1_Workspace/MS1_scheduler_411/Components/Battery/inc" -I"C:/Users/Quent/Desktop/Workspaces/STM_Workspace/MS1_Workspace/MS1_scheduler_411/Components/HMI/inc" -I"C:/Users/Quent/Desktop/Workspaces/STM_Workspace/MS1_Workspace/MS1_scheduler_411/Components/LEDS/inc" -I"C:/Users/Quent/Desktop/Workspaces/STM_Workspace/MS1_Workspace/MS1_scheduler_411/Components/Payload/inc" -I"C:/Users/Quent/Desktop/Workspaces/STM_Workspace/MS1_Workspace/MS1_scheduler_411/Components/Recovery/inc" -I"C:/Users/Quent/Desktop/Workspaces/STM_Workspace/MS1_Workspace/MS1_scheduler_411/Components/Sensors/inc" -I"C:/Users/Quent/Desktop/Workspaces/STM_Workspace/MS1_Workspace/MS1_scheduler_411/ThirdParty/FreeRTOS/include" -I"C:/Users/Quent/Desktop/Workspaces/STM_Workspace/MS1_Workspace/MS1_scheduler_411/ThirdParty/FreeRTOS/portable/GCC/ARM_CM4F" -I"C:/Users/Quent/Desktop/Workspaces/STM_Workspace/MS1_Workspace/MS1_scheduler_411/ThirdParty/SEGGER/Config" -I"C:/Users/Quent/Desktop/Workspaces/STM_Workspace/MS1_Workspace/MS1_scheduler_411/ThirdParty/SEGGER/OS" -I"C:/Users/Quent/Desktop/Workspaces/STM_Workspace/MS1_Workspace/MS1_scheduler_411/ThirdParty/SEGGER/SEGGER" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Components-2f-Sensors

clean-Components-2f-Sensors:
	-$(RM) ./Components/Sensors/API_sensors.d ./Components/Sensors/API_sensors.o ./Components/Sensors/bmp280.d ./Components/Sensors/bmp280.o ./Components/Sensors/mpu6050.d ./Components/Sensors/mpu6050.o

.PHONY: clean-Components-2f-Sensors

