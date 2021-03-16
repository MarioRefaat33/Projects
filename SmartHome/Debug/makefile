################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include system/src/stm32f1-stdperiph/subdir.mk
-include system/src/newlib/subdir.mk
-include system/src/diag/subdir.mk
-include system/src/cortexm/subdir.mk
-include system/src/cmsis/subdir.mk
-include src/MCAL/USART/subdir.mk
-include src/MCAL/SYSTICK/subdir.mk
-include src/MCAL/RCC/subdir.mk
-include src/MCAL/PWM/subdir.mk
-include src/MCAL/NVIC/subdir.mk
-include src/MCAL/GPIO/subdir.mk
-include src/MCAL/EXTI/subdir.mk
-include src/MCAL/AFIO/subdir.mk
-include src/MCAL/ADC/subdir.mk
-include src/HAL/WIFI/subdir.mk
-include src/HAL/TEMP_SENSOR/subdir.mk
-include src/HAL/SERVO/subdir.mk
-include src/HAL/LED/subdir.mk
-include src/HAL/LCD/subdir.mk
-include src/HAL/KeyPad/subdir.mk
-include src/HAL/IR/subdir.mk
-include src/HAL/Gas_Sensor/subdir.mk
-include src/HAL/FLAME_SENSOR/subdir.mk
-include src/HAL/DC_MOTOR/subdir.mk
-include src/HAL/BUZZER/subdir.mk
-include src/APP/subdir.mk
-include src/subdir.mk
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
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
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
SECONDARY_FLASH += \
Smart_Home_FOTA\ _Final.hex \

SECONDARY_SIZE += \
Smart_Home_FOTA\ _Final.siz \


# All Target
all: Smart_Home_FOTA\ _Final.elf secondary-outputs

# Tool invocations
Smart_Home_FOTA\ _Final.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Cross ARM GNU C++ Linker'
	arm-none-eabi-g++ -mcpu=cortex-m3 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -T mem.ld -T libs.ld -T sections.ld -nostartfiles -Xlinker --gc-sections -L"../ldscripts" -Wl,-Map,"Smart_Home_FOTA _Final.map" --specs=nano.specs -o "Smart_Home_FOTA _Final.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Smart_Home_FOTA\ _Final.hex: Smart_Home_FOTA\ _Final.elf
	@echo 'Invoking: Cross ARM GNU Create Flash Image'
	arm-none-eabi-objcopy -O ihex "Smart_Home_FOTA _Final.elf"  "Smart_Home_FOTA _Final.hex"
	@echo 'Finished building: $@'
	@echo ' '

Smart_Home_FOTA\ _Final.siz: Smart_Home_FOTA\ _Final.elf
	@echo 'Invoking: Cross ARM GNU Print Size'
	arm-none-eabi-size --format=berkeley "Smart_Home_FOTA _Final.elf"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(CC_DEPS)$(C++_DEPS)$(OBJS)$(C_UPPER_DEPS)$(CXX_DEPS)$(SECONDARY_FLASH)$(SECONDARY_SIZE)$(ASM_DEPS)$(S_UPPER_DEPS)$(C_DEPS)$(CPP_DEPS) "Smart_Home_FOTA _Final.elf"
	-@echo ' '

secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_SIZE)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
