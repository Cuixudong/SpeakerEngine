################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/RVMSIS/core_riscv.c 

OBJS += \
./src/RVMSIS/core_riscv.o 

C_DEPS += \
./src/RVMSIS/core_riscv.d 


# Each subdirectory must supply rules for building sources it contributes
src/RVMSIS/%.o: ../src/RVMSIS/%.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DDEBUG=1 -I"F:\CubeMX_Prj\F730Test\SpeakerEngine_CH571\src\StdPeriphDriver\inc" -I"F:\CubeMX_Prj\F730Test\SpeakerEngine_CH571\src\RVMSIS" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

