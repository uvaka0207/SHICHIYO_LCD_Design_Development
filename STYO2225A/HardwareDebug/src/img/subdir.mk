################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/img/img.c \
../src/img/img00.c \
../src/img/img01.c \
../src/img/img02.c \
../src/img/img03.c \
../src/img/img_dat.c 

LST += \
img.lst \
img00.lst \
img01.lst \
img02.lst \
img03.lst \
img_dat.lst 

C_DEPS += \
./src/img/img.d \
./src/img/img00.d \
./src/img/img01.d \
./src/img/img02.d \
./src/img/img03.d \
./src/img/img_dat.d 

OBJS += \
./src/img/img.o \
./src/img/img00.o \
./src/img/img01.o \
./src/img/img02.o \
./src/img/img03.o \
./src/img/img_dat.o 

MAP += \
STYO2225A.map 


# Each subdirectory must supply rules for building sources it contributes
src/img/%.o: ../src/img/%.c
	@echo 'Building file: $<'
	$(file > $@.in,-mcpu=cortex-a9 -marm -mlittle-endian -mfloat-abi=hard -mfpu=vfpv3-d16 -fdiagnostics-parseable-fixits -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wnull-dereference -g -gdwarf-4 -I"X:\\GUI\\STYO2225A\\STYO2225A\\src\\mode" -I"X:\\GUI\\STYO2225A\\STYO2225A\\src\\module\\ff" -I"X:/GUI/STYO2225A/STYO2225A/generate" -I"X:/GUI/STYO2225A/STYO2225A/src" -I"X:/GUI/STYO2225A/STYO2225A/src/module" -I"X:/GUI/STYO2225A/STYO2225A/src/inxlib" -I"X:/GUI/STYO2225A/STYO2225A/src/driver/vdc5/inc" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<")
	@arm-none-eabi-gcc @"$@.in"

