################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/StdPeriphDriver/CH57x_adc.c \
../src/StdPeriphDriver/CH57x_clk.c \
../src/StdPeriphDriver/CH57x_flash.c \
../src/StdPeriphDriver/CH57x_gpio.c \
../src/StdPeriphDriver/CH57x_pwm.c \
../src/StdPeriphDriver/CH57x_pwr.c \
../src/StdPeriphDriver/CH57x_spi0.c \
../src/StdPeriphDriver/CH57x_sys.c \
../src/StdPeriphDriver/CH57x_timer0.c \
../src/StdPeriphDriver/CH57x_timer1.c \
../src/StdPeriphDriver/CH57x_timer2.c \
../src/StdPeriphDriver/CH57x_timer3.c \
../src/StdPeriphDriver/CH57x_uart0.c \
../src/StdPeriphDriver/CH57x_uart1.c \
../src/StdPeriphDriver/CH57x_uart2.c \
../src/StdPeriphDriver/CH57x_uart3.c \
../src/StdPeriphDriver/CH57x_usbdev.c \
../src/StdPeriphDriver/CH57x_usbhostBase.c \
../src/StdPeriphDriver/CH57x_usbhostClass.c 

OBJS += \
./src/StdPeriphDriver/CH57x_adc.o \
./src/StdPeriphDriver/CH57x_clk.o \
./src/StdPeriphDriver/CH57x_flash.o \
./src/StdPeriphDriver/CH57x_gpio.o \
./src/StdPeriphDriver/CH57x_pwm.o \
./src/StdPeriphDriver/CH57x_pwr.o \
./src/StdPeriphDriver/CH57x_spi0.o \
./src/StdPeriphDriver/CH57x_sys.o \
./src/StdPeriphDriver/CH57x_timer0.o \
./src/StdPeriphDriver/CH57x_timer1.o \
./src/StdPeriphDriver/CH57x_timer2.o \
./src/StdPeriphDriver/CH57x_timer3.o \
./src/StdPeriphDriver/CH57x_uart0.o \
./src/StdPeriphDriver/CH57x_uart1.o \
./src/StdPeriphDriver/CH57x_uart2.o \
./src/StdPeriphDriver/CH57x_uart3.o \
./src/StdPeriphDriver/CH57x_usbdev.o \
./src/StdPeriphDriver/CH57x_usbhostBase.o \
./src/StdPeriphDriver/CH57x_usbhostClass.o 

C_DEPS += \
./src/StdPeriphDriver/CH57x_adc.d \
./src/StdPeriphDriver/CH57x_clk.d \
./src/StdPeriphDriver/CH57x_flash.d \
./src/StdPeriphDriver/CH57x_gpio.d \
./src/StdPeriphDriver/CH57x_pwm.d \
./src/StdPeriphDriver/CH57x_pwr.d \
./src/StdPeriphDriver/CH57x_spi0.d \
./src/StdPeriphDriver/CH57x_sys.d \
./src/StdPeriphDriver/CH57x_timer0.d \
./src/StdPeriphDriver/CH57x_timer1.d \
./src/StdPeriphDriver/CH57x_timer2.d \
./src/StdPeriphDriver/CH57x_timer3.d \
./src/StdPeriphDriver/CH57x_uart0.d \
./src/StdPeriphDriver/CH57x_uart1.d \
./src/StdPeriphDriver/CH57x_uart2.d \
./src/StdPeriphDriver/CH57x_uart3.d \
./src/StdPeriphDriver/CH57x_usbdev.d \
./src/StdPeriphDriver/CH57x_usbhostBase.d \
./src/StdPeriphDriver/CH57x_usbhostClass.d 


# Each subdirectory must supply rules for building sources it contributes
src/StdPeriphDriver/%.o: ../src/StdPeriphDriver/%.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DDEBUG=1 -I"F:\CubeMX_Prj\F730Test\SpeakerEngine_CH571\src\StdPeriphDriver\inc" -I"F:\CubeMX_Prj\F730Test\SpeakerEngine_CH571\src\RVMSIS" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

