################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/User/Main.c \
../src/User/keyboard.c \
../src/User/lcd.c 

OBJS += \
./src/User/Main.o \
./src/User/keyboard.o \
./src/User/lcd.o 

C_DEPS += \
./src/User/Main.d \
./src/User/keyboard.d \
./src/User/lcd.d 


# Each subdirectory must supply rules for building sources it contributes
src/User/%.o: ../src/User/%.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DDEBUG=1 -I"F:\CubeMX_Prj\F730Test\SpeakerEngine_CH571\src\StdPeriphDriver\inc" -I"F:\CubeMX_Prj\F730Test\SpeakerEngine_CH571\src\RVMSIS" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

