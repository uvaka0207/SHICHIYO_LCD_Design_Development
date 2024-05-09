################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/driver/usb/r_usb_hmsc/src/r_tfat_drv_if_usb.c \
../src/driver/usb/r_usb_hmsc/src/r_usb_hmsc_api.c \
../src/driver/usb/r_usb_hmsc/src/r_usb_hmsc_driver.c \
../src/driver/usb/r_usb_hmsc/src/r_usb_hstorage_driver.c \
../src/driver/usb/r_usb_hmsc/src/r_usb_hstorage_driver_api.c 

C_DEPS += \
./src/driver/usb/r_usb_hmsc/src/r_tfat_drv_if_usb.d \
./src/driver/usb/r_usb_hmsc/src/r_usb_hmsc_api.d \
./src/driver/usb/r_usb_hmsc/src/r_usb_hmsc_driver.d \
./src/driver/usb/r_usb_hmsc/src/r_usb_hstorage_driver.d \
./src/driver/usb/r_usb_hmsc/src/r_usb_hstorage_driver_api.d 

OBJS += \
./src/driver/usb/r_usb_hmsc/src/r_tfat_drv_if_usb.o \
./src/driver/usb/r_usb_hmsc/src/r_usb_hmsc_api.o \
./src/driver/usb/r_usb_hmsc/src/r_usb_hmsc_driver.o \
./src/driver/usb/r_usb_hmsc/src/r_usb_hstorage_driver.o \
./src/driver/usb/r_usb_hmsc/src/r_usb_hstorage_driver_api.o 


# Each subdirectory must supply rules for building sources it contributes
src/driver/usb/r_usb_hmsc/src/%.o: ../src/driver/usb/r_usb_hmsc/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-a9 -march=armv7-a -marm -mlittle-endian -mfloat-abi=hard -mfpu=vfpv3-d16 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wnull-dereference -g -Wstack-usage=500 -I"D:\Project\STYO\STYO2225A\STYO2225A\src\driver\usb\r_usb_hmsc\src\ff14" -I"D:\Project\STYO\STYO2225A\STYO2225A\src\driver\usb\r_usb_basic\src\hw\inc" -I"D:\Project\STYO\STYO2225A\STYO2225A\src\driver\usb\r_usb_hmsc\ref" -I"D:\Project\STYO\STYO2225A\STYO2225A\src\driver\usb\r_usb_basic\src\driver\inc" -I"D:\Project\STYO\STYO2225A\STYO2225A\src\driver\usb\userdef" -I"D:\Project\STYO\STYO2225A\STYO2225A\src\driver\usb" -I"D:\Project\STYO\STYO2225A\STYO2225A\src\driver\usb\r_usb_basic\src\hw" -I"D:\Project\STYO\STYO2225A\STYO2225A\src\driver\usb\r_usb_hmsc" -I"D:\Project\STYO\STYO2225A\STYO2225A\src\driver\usb\r_usb_hmsc\src" -I"D:\Project\STYO\STYO2225A\STYO2225A\src\driver\usb\r_usb_basic\src" -I"D:\Project\STYO\STYO2225A\STYO2225A\src\driver\usb\r_usb_hmsc\src\inc" -I"D:\Project\STYO\STYO2225A\STYO2225A\src\driver\usb\r_usb_basic" -I"D:\Project\STYO\STYO2225A\STYO2225A\src\driver\usb\r_usb_basic\src\driver" -I"D:/Project/STYO/STYO2225A/STYO2225A/generate" -I"D:/Project/STYO/STYO2225A/STYO2225A/src" -I"D:/Project/STYO/STYO2225A/STYO2225A/src/module" -I"D:/Project/STYO/STYO2225A/STYO2225A/src/inxlib" -I"D:/Project/STYO/STYO2225A/STYO2225A/src/driver/vdc5/inc" -std=gnu11 -Wstrict-prototypes -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


