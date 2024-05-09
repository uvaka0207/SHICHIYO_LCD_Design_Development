################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/inxlib/inx_tool.c \
../src/inxlib/timer.c 

C_DEPS += \
./src/inxlib/inx_tool.d \
./src/inxlib/timer.d 

OBJS += \
./src/inxlib/inx_tool.o \
./src/inxlib/timer.o 


# Each subdirectory must supply rules for building sources it contributes
src/inxlib/%.o: ../src/inxlib/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-a9 -march=armv7-a -marm -mlittle-endian -mfloat-abi=hard -mfpu=vfpv3-d16 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wnull-dereference -g -Wstack-usage=500 -I"D:\Project\STYO\STYO2225A\STYO2225A\src\driver\usb\r_usb_hmsc\src\ff14" -I"D:\Project\STYO\STYO2225A\STYO2225A\src\driver\usb\r_usb_basic\src\hw\inc" -I"D:\Project\STYO\STYO2225A\STYO2225A\src\driver\usb\r_usb_hmsc\ref" -I"D:\Project\STYO\STYO2225A\STYO2225A\src\driver\usb\r_usb_basic\src\driver\inc" -I"D:\Project\STYO\STYO2225A\STYO2225A\src\driver\usb\userdef" -I"D:\Project\STYO\STYO2225A\STYO2225A\src\driver\usb" -I"D:\Project\STYO\STYO2225A\STYO2225A\src\driver\usb\r_usb_basic\src\hw" -I"D:\Project\STYO\STYO2225A\STYO2225A\src\driver\usb\r_usb_hmsc" -I"D:\Project\STYO\STYO2225A\STYO2225A\src\driver\usb\r_usb_hmsc\src" -I"D:\Project\STYO\STYO2225A\STYO2225A\src\driver\usb\r_usb_basic\src" -I"D:\Project\STYO\STYO2225A\STYO2225A\src\driver\usb\r_usb_hmsc\src\inc" -I"D:\Project\STYO\STYO2225A\STYO2225A\src\driver\usb\r_usb_basic" -I"D:\Project\STYO\STYO2225A\STYO2225A\src\driver\usb\r_usb_basic\src\driver" -I"D:/Project/STYO/STYO2225A/STYO2225A/generate" -I"D:/Project/STYO/STYO2225A/STYO2225A/src" -I"D:/Project/STYO/STYO2225A/STYO2225A/src/module" -I"D:/Project/STYO/STYO2225A/STYO2225A/src/inxlib" -I"D:/Project/STYO/STYO2225A/STYO2225A/src/driver/vdc5/inc" -std=gnu11 -Wstrict-prototypes -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


