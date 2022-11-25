################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/User/subdir.mk
-include src/StdPeriphDriver/subdir.mk
-include src/Startup/subdir.mk
-include src/RVMSIS/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
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
SECONDARY_FLASH += \
SpeakerEngine.hex \

SECONDARY_SIZE += \
SpeakerEngine.siz \


# All Target
all: SpeakerEngine.elf secondary-outputs

# Tool invocations
SpeakerEngine.elf: $(OBJS) $(USER_OBJS)
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -T "F:\CubeMX_Prj\F730Test\SpeakerEngine_CH571\src\Ld\Link.ld" -nostartfiles -Xlinker --gc-sections -L"../" -L"F:\CubeMX_Prj\F730Test\SpeakerEngine_CH571\src\StdPeriphDriver" -Xlinker --print-memory-usage -Wl,-Map,"SpeakerEngine.map" --specs=nano.specs --specs=nosys.specs -o "SpeakerEngine.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@	@
SpeakerEngine.hex: SpeakerEngine.elf
	@	riscv-none-embed-objcopy -O ihex "SpeakerEngine.elf"  "SpeakerEngine.hex"
	@	@
SpeakerEngine.siz: SpeakerEngine.elf
	@	riscv-none-embed-size --format=berkeley "SpeakerEngine.elf"
	@	@
# Other Targets
clean:
	-$(RM) $(ASM_UPPER_DEPS)$(OBJS)$(SECONDARY_FLASH)$(SECONDARY_SIZE)$(ASM_DEPS)$(S_DEPS)$(S_UPPER_DEPS)$(C_DEPS) SpeakerEngine.elf
	-@
secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_SIZE)

.PHONY: all clean dependents

-include ../makefile.targets
