################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/mode/mode.c \
../src/mode/mode_codelist.c \
../src/mode/mode_config.c \
../src/mode/mode_detail.c \
../src/mode/mode_home.c \
../src/mode/mode_key00.c \
../src/mode/mode_key01.c \
../src/mode/mode_key02.c \
../src/mode/mode_process00.c \
../src/mode/mode_process01.c 

LST += \
mode.lst \
mode_codelist.lst \
mode_config.lst \
mode_detail.lst \
mode_home.lst \
mode_key00.lst \
mode_key01.lst \
mode_key02.lst \
mode_process00.lst \
mode_process01.lst 

C_DEPS += \
./src/mode/mode.d \
./src/mode/mode_codelist.d \
./src/mode/mode_config.d \
./src/mode/mode_detail.d \
./src/mode/mode_home.d \
./src/mode/mode_key00.d \
./src/mode/mode_key01.d \
./src/mode/mode_key02.d \
./src/mode/mode_process00.d \
./src/mode/mode_process01.d 

OBJS += \
./src/mode/mode.o \
./src/mode/mode_codelist.o \
./src/mode/mode_config.o \
./src/mode/mode_detail.o \
./src/mode/mode_home.o \
./src/mode/mode_key00.o \
./src/mode/mode_key01.o \
./src/mode/mode_key02.o \
./src/mode/mode_process00.o \
./src/mode/mode_process01.o 

MAP += \
STYO2225A.map 


# Each subdirectory must supply rules for building sources it contributes
src/mode/%.o: ../src/mode/%.c
	@echo 'Building file: $<'
	$(file > $@.in,-mcpu=cortex-a9 -marm -mlittle-endian -mfloat-abi=hard -mfpu=vfpv3-d16 -fdiagnostics-parseable-fixits -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wnull-dereference -g -gdwarf-4 -I"X:\\GUI\\STYO2225A\\STYO2225A\\src\\mode" -I"X:\\GUI\\STYO2225A\\STYO2225A\\src\\module\\ff" -I"X:/GUI/STYO2225A/STYO2225A/generate" -I"X:/GUI/STYO2225A/STYO2225A/src" -I"X:/GUI/STYO2225A/STYO2225A/src/module" -I"X:/GUI/STYO2225A/STYO2225A/src/inxlib" -I"X:/GUI/STYO2225A/STYO2225A/src/driver/vdc5/inc" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<")
	@arm-none-eabi-gcc @"$@.in"

