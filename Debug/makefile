################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include ThirdParty/SEGGER/SEGGER/Syscalls/subdir.mk
-include ThirdParty/SEGGER/SEGGER/subdir.mk
-include ThirdParty/SEGGER/OS/subdir.mk
-include ThirdParty/SEGGER/Config/subdir.mk
-include ThirdParty/FreeRTOS/portable/MemMang/subdir.mk
-include ThirdParty/FreeRTOS/portable/GCC/ARM_CM4F/subdir.mk
-include ThirdParty/FreeRTOS/subdir.mk
-include Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include Components/Sensors/subdir.mk
-include Components/Recovery/subdir.mk
-include Components/Payload/subdir.mk
-include Components/LEDS/subdir.mk
-include Components/HMI/subdir.mk
-include Components/Battery/subdir.mk
-include Components/Audio/subdir.mk
-include Components/Application/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := MS1_scheduler_411
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
MS1_scheduler_411.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
MS1_scheduler_411.list \

OBJCOPY_BIN += \
MS1_scheduler_411.bin \


# All Target
all: main-build

# Main-build Target
main-build: MS1_scheduler_411.elf secondary-outputs

# Tool invocations
MS1_scheduler_411.elf: $(OBJS) $(USER_OBJS) C:\Users\Quent\Desktop\Workspaces\STM_Workspace\MS1_Workspace\MS1_scheduler_411\STM32F411RETX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "MS1_scheduler_411.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Users\Quent\Desktop\Workspaces\STM_Workspace\MS1_Workspace\MS1_scheduler_411\STM32F411RETX_FLASH.ld" --specs=nosys.specs -Wl,-Map="MS1_scheduler_411.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

MS1_scheduler_411.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "MS1_scheduler_411.list"
	@echo 'Finished building: $@'
	@echo ' '

MS1_scheduler_411.bin: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "MS1_scheduler_411.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) MS1_scheduler_411.bin MS1_scheduler_411.elf MS1_scheduler_411.list default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
