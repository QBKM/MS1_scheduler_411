################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ThirdParty/SEGGER/OS/SEGGER_SYSVIEW_FreeRTOS.c 

OBJS += \
./ThirdParty/SEGGER/OS/SEGGER_SYSVIEW_FreeRTOS.o 

C_DEPS += \
./ThirdParty/SEGGER/OS/SEGGER_SYSVIEW_FreeRTOS.d 


# Each subdirectory must supply rules for building sources it contributes
ThirdParty/SEGGER/OS/%.o: ../ThirdParty/SEGGER/OS/%.c ThirdParty/SEGGER/OS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I"C:/Users/Quent/Desktop/Workspaces/STM_Workspace/MS1_Workspace/MS1_scheduler_411/Configuration" -I"C:/Users/Quent/Desktop/Workspaces/STM_Workspace/MS1_Workspace/MS1_scheduler_411/Components/Application/inc" -I"C:/Users/Quent/Desktop/Workspaces/STM_Workspace/MS1_Workspace/MS1_scheduler_411/Components/Audio/inc" -I"C:/Users/Quent/Desktop/Workspaces/STM_Workspace/MS1_Workspace/MS1_scheduler_411/Components/Battery/inc" -I"C:/Users/Quent/Desktop/Workspaces/STM_Workspace/MS1_Workspace/MS1_scheduler_411/Components/HMI/inc" -I"C:/Users/Quent/Desktop/Workspaces/STM_Workspace/MS1_Workspace/MS1_scheduler_411/Components/LEDS/inc" -I"C:/Users/Quent/Desktop/Workspaces/STM_Workspace/MS1_Workspace/MS1_scheduler_411/Components/Payload/inc" -I"C:/Users/Quent/Desktop/Workspaces/STM_Workspace/MS1_Workspace/MS1_scheduler_411/Components/Recovery/inc" -I"C:/Users/Quent/Desktop/Workspaces/STM_Workspace/MS1_Workspace/MS1_scheduler_411/Components/Sensors/inc" -I"C:/Users/Quent/Desktop/Workspaces/STM_Workspace/MS1_Workspace/MS1_scheduler_411/ThirdParty/FreeRTOS/include" -I"C:/Users/Quent/Desktop/Workspaces/STM_Workspace/MS1_Workspace/MS1_scheduler_411/ThirdParty/FreeRTOS/portable/GCC/ARM_CM4F" -I"C:/Users/Quent/Desktop/Workspaces/STM_Workspace/MS1_Workspace/MS1_scheduler_411/ThirdParty/SEGGER/Config" -I"C:/Users/Quent/Desktop/Workspaces/STM_Workspace/MS1_Workspace/MS1_scheduler_411/ThirdParty/SEGGER/OS" -I"C:/Users/Quent/Desktop/Workspaces/STM_Workspace/MS1_Workspace/MS1_scheduler_411/ThirdParty/SEGGER/SEGGER" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-ThirdParty-2f-SEGGER-2f-OS

clean-ThirdParty-2f-SEGGER-2f-OS:
	-$(RM) ./ThirdParty/SEGGER/OS/SEGGER_SYSVIEW_FreeRTOS.d ./ThirdParty/SEGGER/OS/SEGGER_SYSVIEW_FreeRTOS.o

.PHONY: clean-ThirdParty-2f-SEGGER-2f-OS

