################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
F:/STM32资料/F407/热风枪/CH571/EVT/EXAM/SRC/StdPeriphDriver/CH57x_adc.c \
F:/STM32资料/F407/热风枪/CH571/EVT/EXAM/SRC/StdPeriphDriver/CH57x_clk.c \
F:/STM32资料/F407/热风枪/CH571/EVT/EXAM/SRC/StdPeriphDriver/CH57x_flash.c \
F:/STM32资料/F407/热风枪/CH571/EVT/EXAM/SRC/StdPeriphDriver/CH57x_gpio.c \
F:/STM32资料/F407/热风枪/CH571/EVT/EXAM/SRC/StdPeriphDriver/CH57x_pwr.c \
F:/STM32资料/F407/热风枪/CH571/EVT/EXAM/SRC/StdPeriphDriver/CH57x_spi0.c \
F:/STM32资料/F407/热风枪/CH571/EVT/EXAM/SRC/StdPeriphDriver/CH57x_sys.c \
F:/STM32资料/F407/热风枪/CH571/EVT/EXAM/SRC/StdPeriphDriver/CH57x_uart0.c \
F:/STM32资料/F407/热风枪/CH571/EVT/EXAM/SRC/StdPeriphDriver/CH57x_uart1.c \
F:/STM32资料/F407/热风枪/CH571/EVT/EXAM/SRC/StdPeriphDriver/CH57x_usbdev.c 

OBJS += \
./StdPeriphDriver/CH57x_adc.o \
./StdPeriphDriver/CH57x_clk.o \
./StdPeriphDriver/CH57x_flash.o \
./StdPeriphDriver/CH57x_gpio.o \
./StdPeriphDriver/CH57x_pwr.o \
./StdPeriphDriver/CH57x_spi0.o \
./StdPeriphDriver/CH57x_sys.o \
./StdPeriphDriver/CH57x_uart0.o \
./StdPeriphDriver/CH57x_uart1.o \
./StdPeriphDriver/CH57x_usbdev.o 

C_DEPS += \
./StdPeriphDriver/CH57x_adc.d \
./StdPeriphDriver/CH57x_clk.d \
./StdPeriphDriver/CH57x_flash.d \
./StdPeriphDriver/CH57x_gpio.d \
./StdPeriphDriver/CH57x_pwr.d \
./StdPeriphDriver/CH57x_spi0.d \
./StdPeriphDriver/CH57x_sys.d \
./StdPeriphDriver/CH57x_uart0.d \
./StdPeriphDriver/CH57x_uart1.d \
./StdPeriphDriver/CH57x_usbdev.d 


# Each subdirectory must supply rules for building sources it contributes
StdPeriphDriver/CH57x_adc.o: F:/STM32资料/F407/热风枪/CH571/EVT/EXAM/SRC/StdPeriphDriver/CH57x_adc.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DDEBUG=1 -I"F:\STM32资料\F407\热风枪\CH571\EVT\EXAM\SRC\StdPeriphDriver\inc" -I"F:\STM32资料\F407\热风枪\CH571\EVT\EXAM\SRC\RVMSIS" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
StdPeriphDriver/CH57x_clk.o: F:/STM32资料/F407/热风枪/CH571/EVT/EXAM/SRC/StdPeriphDriver/CH57x_clk.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DDEBUG=1 -I"F:\STM32资料\F407\热风枪\CH571\EVT\EXAM\SRC\StdPeriphDriver\inc" -I"F:\STM32资料\F407\热风枪\CH571\EVT\EXAM\SRC\RVMSIS" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
StdPeriphDriver/CH57x_flash.o: F:/STM32资料/F407/热风枪/CH571/EVT/EXAM/SRC/StdPeriphDriver/CH57x_flash.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DDEBUG=1 -I"F:\STM32资料\F407\热风枪\CH571\EVT\EXAM\SRC\StdPeriphDriver\inc" -I"F:\STM32资料\F407\热风枪\CH571\EVT\EXAM\SRC\RVMSIS" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
StdPeriphDriver/CH57x_gpio.o: F:/STM32资料/F407/热风枪/CH571/EVT/EXAM/SRC/StdPeriphDriver/CH57x_gpio.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DDEBUG=1 -I"F:\STM32资料\F407\热风枪\CH571\EVT\EXAM\SRC\StdPeriphDriver\inc" -I"F:\STM32资料\F407\热风枪\CH571\EVT\EXAM\SRC\RVMSIS" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
StdPeriphDriver/CH57x_pwr.o: F:/STM32资料/F407/热风枪/CH571/EVT/EXAM/SRC/StdPeriphDriver/CH57x_pwr.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DDEBUG=1 -I"F:\STM32资料\F407\热风枪\CH571\EVT\EXAM\SRC\StdPeriphDriver\inc" -I"F:\STM32资料\F407\热风枪\CH571\EVT\EXAM\SRC\RVMSIS" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
StdPeriphDriver/CH57x_spi0.o: F:/STM32资料/F407/热风枪/CH571/EVT/EXAM/SRC/StdPeriphDriver/CH57x_spi0.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DDEBUG=1 -I"F:\STM32资料\F407\热风枪\CH571\EVT\EXAM\SRC\StdPeriphDriver\inc" -I"F:\STM32资料\F407\热风枪\CH571\EVT\EXAM\SRC\RVMSIS" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
StdPeriphDriver/CH57x_sys.o: F:/STM32资料/F407/热风枪/CH571/EVT/EXAM/SRC/StdPeriphDriver/CH57x_sys.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DDEBUG=1 -I"F:\STM32资料\F407\热风枪\CH571\EVT\EXAM\SRC\StdPeriphDriver\inc" -I"F:\STM32资料\F407\热风枪\CH571\EVT\EXAM\SRC\RVMSIS" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
StdPeriphDriver/CH57x_uart0.o: F:/STM32资料/F407/热风枪/CH571/EVT/EXAM/SRC/StdPeriphDriver/CH57x_uart0.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DDEBUG=1 -I"F:\STM32资料\F407\热风枪\CH571\EVT\EXAM\SRC\StdPeriphDriver\inc" -I"F:\STM32资料\F407\热风枪\CH571\EVT\EXAM\SRC\RVMSIS" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
StdPeriphDriver/CH57x_uart1.o: F:/STM32资料/F407/热风枪/CH571/EVT/EXAM/SRC/StdPeriphDriver/CH57x_uart1.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DDEBUG=1 -I"F:\STM32资料\F407\热风枪\CH571\EVT\EXAM\SRC\StdPeriphDriver\inc" -I"F:\STM32资料\F407\热风枪\CH571\EVT\EXAM\SRC\RVMSIS" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
StdPeriphDriver/CH57x_usbdev.o: F:/STM32资料/F407/热风枪/CH571/EVT/EXAM/SRC/StdPeriphDriver/CH57x_usbdev.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DDEBUG=1 -I"F:\STM32资料\F407\热风枪\CH571\EVT\EXAM\SRC\StdPeriphDriver\inc" -I"F:\STM32资料\F407\热风枪\CH571\EVT\EXAM\SRC\RVMSIS" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

