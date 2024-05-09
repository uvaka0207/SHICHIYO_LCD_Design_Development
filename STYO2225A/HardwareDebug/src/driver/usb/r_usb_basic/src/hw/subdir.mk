################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/driver/usb/r_usb_basic/src/hw/r_usb_creg_abs.c \
../src/driver/usb/r_usb_basic/src/hw/r_usb_creg_access.c \
../src/driver/usb/r_usb_basic/src/hw/r_usb_dma.c \
../src/driver/usb/r_usb_basic/src/hw/r_usb_hostelectrical.c \
../src/driver/usb/r_usb_basic/src/hw/r_usb_hreg_abs.c \
../src/driver/usb/r_usb_basic/src/hw/r_usb_hreg_access.c \
../src/driver/usb/r_usb_basic/src/hw/r_usb_preg_abs.c \
../src/driver/usb/r_usb_basic/src/hw/r_usb_preg_access.c \
../src/driver/usb/r_usb_basic/src/hw/r_usb_rz_mcu.c 

C_DEPS += \
./src/driver/usb/r_usb_basic/src/hw/r_usb_creg_abs.d \
./src/driver/usb/r_usb_basic/src/hw/r_usb_creg_access.d \
./src/driver/usb/r_usb_basic/src/hw/r_usb_dma.d \
./src/driver/usb/r_usb_basic/src/hw/r_usb_hostelectrical.d \
./src/driver/usb/r_usb_basic/src/hw/r_usb_hreg_abs.d \
./src/driver/usb/r_usb_basic/src/hw/r_usb_hreg_access.d \
./src/driver/usb/r_usb_basic/src/hw/r_usb_preg_abs.d \
./src/driver/usb/r_usb_basic/src/hw/r_usb_preg_access.d \
./src/driver/usb/r_usb_basic/src/hw/r_usb_rz_mcu.d 

OBJS += \
./src/driver/usb/r_usb_basic/src/hw/r_usb_creg_abs.o \
./src/driver/usb/r_usb_basic/src/hw/r_usb_creg_access.o \
./src/driver/usb/r_usb_basic/src/hw/r_usb_dma.o \
./src/driver/usb/r_usb_basic/src/hw/r_usb_hostelectrical.o \
./src/driver/usb/r_usb_basic/src/hw/r_usb_hreg_abs.o \
./src/driver/usb/r_usb_basic/src/hw/r_usb_hreg_access.o \
./src/driver/usb/r_usb_basic/src/hw/r_usb_preg_abs.o \
./src/driver/usb/r_usb_basic/src/hw/r_usb_preg_access.o \
./src/driver/usb/r_usb_basic/src/hw/r_usb_rz_mcu.o 


# Each subdirectory must supply rules for building sources it contributes
src/driver/usb/r_usb_basic/src/hw/%.o: ../src/driver/usb/r_usb_basic/src/hw/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-a9 -march=armv7-a -marm -mlittle-endian -mfloat-abi=hard -mfpu=vfpv3-d16 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wnull-dereference -g -Wstack-usage=500 -I"D:\Project\STYO\STYO2225A\STYO2225A\src\driver\usb\r_usb_hmsc\src\ff14" -I"D:\Project\STYO\STYO2225A\STYO2225A\src\driver\usb\r_usb_basic\src\hw\inc" -I"D:\Project\STYO\STYO2225A\STYO2225A\src\driver\usb\r_usb_hmsc\ref" -I"D:\Project\STYO\STYO2225A\STYO2225A\src\driver\usb\r_usb_basic\src\driver\inc" -I"D:\Project\STYO\STYO2225A\STYO2225A\src\driver\usb\userdef" -I"D:\Project\STYO\STYO2225A\STYO2225A\src\driver\usb" -I"D:\Project\STYO\STYO2225A\STYO2225A\src\driver\usb\r_usb_basic\src\hw" -I"D:\Project\STYO\STYO2225A\STYO2225A\src\driver\usb\r_usb_hmsc" -I"D:\Project\STYO\STYO2225A\STYO2225A\src\driver\usb\r_usb_hmsc\src" -I"D:\Project\STYO\STYO2225A\STYO2225A\src\driver\usb\r_usb_basic\src" -I"D:\Project\STYO\STYO2225A\STYO2225A\src\driver\usb\r_usb_hmsc\src\inc" -I"D:\Project\STYO\STYO2225A\STYO2225A\src\driver\usb\r_usb_basic" -I"D:\Project\STYO\STYO2225A\STYO2225A\src\driver\usb\r_usb_basic\src\driver" -I"D:/Project/STYO/STYO2225A/STYO2225A/generate" -I"D:/Project/STYO/STYO2225A/STYO2225A/src" -I"D:/Project/STYO/STYO2225A/STYO2225A/src/module" -I"D:/Project/STYO/STYO2225A/STYO2225A/src/inxlib" -I"D:/Project/STYO/STYO2225A/STYO2225A/src/driver/vdc5/inc" -std=gnu11 -Wstrict-prototypes -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


