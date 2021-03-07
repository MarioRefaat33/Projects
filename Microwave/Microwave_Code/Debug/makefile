################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/TIMER/Timer1/subdir.mk
-include MCAL/TIMER/Timer0/subdir.mk
-include MCAL/INTERRUPT/subdir.mk
-include MCAL/GIE/subdir.mk
-include MCAL/DIO/subdir.mk
-include MCAL/ADC/subdir.mk
-include HAL/SENSORS/POT/subdir.mk
-include HAL/SENSORS/LM35/subdir.mk
-include HAL/MOTORS/subdir.mk
-include HAL/LED/subdir.mk
-include HAL/LCD/subdir.mk
-include HAL/KEYPAD/subdir.mk
-include HAL/BUZZERS/subdir.mk
-include APP/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
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
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Microwave.lss \

FLASH_IMAGE += \
Microwave.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Microwave.elf secondary-outputs

# Tool invocations
Microwave.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Microwave.map -mmcu=atmega32 -o "Microwave.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Microwave.lss: Microwave.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Microwave.elf  >"Microwave.lss"
	@echo 'Finished building: $@'
	@echo ' '

Microwave.hex: Microwave.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Microwave.elf  "Microwave.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Microwave.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Microwave.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Microwave.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
