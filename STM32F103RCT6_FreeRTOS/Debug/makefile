################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include source/subdir.mk
-include drivers/FreeRTOS/portable/subdir.mk
-include drivers/FreeRTOS/CMSIS_RTOS_V2/subdir.mk
-include drivers/FreeRTOS/subdir.mk
-include drivers/subdir.mk
-include Project_Setting/StartupCode/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
STM32F103RCT6_FreeRTOS.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
STM32F103RCT6_FreeRTOS.list \

OBJCOPY_HEX += \
STM32F103RCT6_FreeRTOS.hex \

OBJCOPY_BIN += \
STM32F103RCT6_FreeRTOS.bin \

OBJCOPY_SREC += \
STM32F103RCT6_FreeRTOS.srec \


# All Target
all: STM32F103RCT6_FreeRTOS.elf secondary-outputs

# Tool invocations
STM32F103RCT6_FreeRTOS.elf: $(OBJS) $(USER_OBJS) E:\STM32CubeIDE\workspace_1.4.0\STM32F103RCT6_FreeRTOS\Project_Setting\LinkerFiles\STM32F103RCTX_FLASH.ld
	arm-none-eabi-g++ -o "STM32F103RCT6_FreeRTOS.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"E:\STM32CubeIDE\workspace_1.4.0\STM32F103RCT6_FreeRTOS\Project_Setting\LinkerFiles\STM32F103RCTX_FLASH.ld" -Wl,-Map="STM32F103RCT6_FreeRTOS.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -lstdc++ -lsupc++ -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

STM32F103RCT6_FreeRTOS.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "STM32F103RCT6_FreeRTOS.list"
	@echo 'Finished building: $@'
	@echo ' '

STM32F103RCT6_FreeRTOS.hex: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "STM32F103RCT6_FreeRTOS.hex"
	@echo 'Finished building: $@'
	@echo ' '

STM32F103RCT6_FreeRTOS.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "STM32F103RCT6_FreeRTOS.bin"
	@echo 'Finished building: $@'
	@echo ' '

STM32F103RCT6_FreeRTOS.srec: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O srec $(EXECUTABLES) "STM32F103RCT6_FreeRTOS.srec"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX) $(OBJCOPY_BIN) $(OBJCOPY_SREC)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
