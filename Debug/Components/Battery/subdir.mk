################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Components/Battery/API_battery.c 

OBJS += \
./Components/Battery/API_battery.o 

C_DEPS += \
./Components/Battery/API_battery.d 


# Each subdirectory must supply rules for building sources it contributes
Components/Battery/%.o: ../Components/Battery/%.c Components/Battery/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I"C:/Users/Quent/Desktop/Workspaces/STM_Workspace/MS1_Workspace/MS1_scheduler_411/Configuration" -I"C:/Users/Quent/Desktop/Workspaces/STM_Workspace/MS1_Workspace/MS1_scheduler_411/Components/Application/inc" -I"C:/Users/Quent/Desktop/Workspaces/STM_Workspace/MS1_Workspace/MS1_scheduler_411/Components/Audio/inc" -I"C:/Users/Quent/Desktop/Workspaces/STM_Workspace/MS1_Workspace/MS1_scheduler_411/Components/Battery/inc" -I"C:/Users/Quent/Desktop/Workspaces/STM_Workspace/MS1_Workspace/MS1_scheduler_411/Components/HMI/inc" -I"C:/Users/Quent/Desktop/Workspaces/STM_Workspace/MS1_Workspace/MS1_scheduler_411/Components/LEDS/inc" -I"C:/Users/Quent/Desktop/Workspaces/STM_Workspace/MS1_Workspace/MS1_scheduler_411/Components/Payload/inc" -I"C:/Users/Quent/Desktop/Workspaces/STM_Workspace/MS1_Workspace/MS1_scheduler_411/Components/Recovery/inc" -I"C:/Users/Quent/Desktop/Workspaces/STM_Workspace/MS1_Workspace/MS1_scheduler_411/Components/Sensors/inc" -I"C:/Users/Quent/Desktop/Workspaces/STM_Workspace/MS1_Workspace/MS1_scheduler_411/ThirdParty/FreeRTOS/include" -I"C:/Users/Quent/Desktop/Workspaces/STM_Workspace/MS1_Workspace/MS1_scheduler_411/ThirdParty/FreeRTOS/portable/GCC/ARM_CM4F" -I"C:/Users/Quent/Desktop/Workspaces/STM_Workspace/MS1_Workspace/MS1_scheduler_411/ThirdParty/SEGGER/Config" -I"C:/Users/Quent/Desktop/Workspaces/STM_Workspace/MS1_Workspace/MS1_scheduler_411/ThirdParty/SEGGER/OS" -I"C:/Users/Quent/Desktop/Workspaces/STM_Workspace/MS1_Workspace/MS1_scheduler_411/ThirdParty/SEGGER/SEGGER" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Components-2f-Battery

clean-Components-2f-Battery:
	-$(RM) ./Components/Battery/API_battery.d ./Components/Battery/API_battery.o

.PHONY: clean-Components-2f-Battery

