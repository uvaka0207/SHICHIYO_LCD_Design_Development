################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/font/FONT00.c \
../src/font/font_data.c \
../src/font/font_style.c 

LST += \
FONT00.lst \
font_data.lst \
font_style.lst 

C_DEPS += \
./src/font/FONT00.d \
./src/font/font_data.d \
./src/font/font_style.d 

OBJS += \
./src/font/FONT00.o \
./src/font/font_data.o \
./src/font/font_style.o 

MAP += \
STYO2225A.map 


# Each subdirectory must supply rules for building sources it contributes
src/font/%.o: ../src/font/%.c
	@echo 'Building file: $<'
	$(file > $@.in,-mcpu=cortex-a9 -marm -mlittle-endian -mfloat-abi=hard -mfpu=vfpv3-d16 -fdiagnostics-parseable-fixits -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wnull-dereference -g -gdwarf-4 -I"X:\\GUI\\STYO2225A\\STYO2225A\\src\\mode" -I"X:\\GUI\\STYO2225A\\STYO2225A\\src\\module\\ff" -I"X:/GUI/STYO2225A/STYO2225A/generate" -I"X:/GUI/STYO2225A/STYO2225A/src" -I"X:/GUI/STYO2225A/STYO2225A/src/module" -I"X:/GUI/STYO2225A/STYO2225A/src/inxlib" -I"X:/GUI/STYO2225A/STYO2225A/src/driver/vdc5/inc" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<")
	@arm-none-eabi-gcc @"$@.in"

