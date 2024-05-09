################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/layer/layer.c \
../src/layer/layer_L_CODELIST00.c \
../src/layer/layer_L_CONFIGURATION00.c \
../src/layer/layer_L_DETAIL00.c \
../src/layer/layer_L_HOME00.c \
../src/layer/layer_L_KEY00.c \
../src/layer/layer_L_KEY01.c \
../src/layer/layer_L_KEY02.c \
../src/layer/layer_L_PROCESS00.c \
../src/layer/layer_L_PROCESS01.c \
../src/layer/layer_L_W_CONFIG00.c \
../src/layer/layer_L_W_CONFIG01.c \
../src/layer/layer_L_W_MODESELECT00.c \
../src/layer/layer_L_W_SETTING00.c \
../src/layer/layer_L_W_SETTING01.c \
../src/layer/layer_L_W_SETTING02.c \
../src/layer/layer_L_W_SETTING03.c 

LST += \
layer.lst \
layer_L_CODELIST00.lst \
layer_L_CONFIGURATION00.lst \
layer_L_DETAIL00.lst \
layer_L_HOME00.lst \
layer_L_KEY00.lst \
layer_L_KEY01.lst \
layer_L_KEY02.lst \
layer_L_PROCESS00.lst \
layer_L_PROCESS01.lst \
layer_L_W_CONFIG00.lst \
layer_L_W_CONFIG01.lst \
layer_L_W_MODESELECT00.lst \
layer_L_W_SETTING00.lst \
layer_L_W_SETTING01.lst \
layer_L_W_SETTING02.lst \
layer_L_W_SETTING03.lst 

C_DEPS += \
./src/layer/layer.d \
./src/layer/layer_L_CODELIST00.d \
./src/layer/layer_L_CONFIGURATION00.d \
./src/layer/layer_L_DETAIL00.d \
./src/layer/layer_L_HOME00.d \
./src/layer/layer_L_KEY00.d \
./src/layer/layer_L_KEY01.d \
./src/layer/layer_L_KEY02.d \
./src/layer/layer_L_PROCESS00.d \
./src/layer/layer_L_PROCESS01.d \
./src/layer/layer_L_W_CONFIG00.d \
./src/layer/layer_L_W_CONFIG01.d \
./src/layer/layer_L_W_MODESELECT00.d \
./src/layer/layer_L_W_SETTING00.d \
./src/layer/layer_L_W_SETTING01.d \
./src/layer/layer_L_W_SETTING02.d \
./src/layer/layer_L_W_SETTING03.d 

OBJS += \
./src/layer/layer.o \
./src/layer/layer_L_CODELIST00.o \
./src/layer/layer_L_CONFIGURATION00.o \
./src/layer/layer_L_DETAIL00.o \
./src/layer/layer_L_HOME00.o \
./src/layer/layer_L_KEY00.o \
./src/layer/layer_L_KEY01.o \
./src/layer/layer_L_KEY02.o \
./src/layer/layer_L_PROCESS00.o \
./src/layer/layer_L_PROCESS01.o \
./src/layer/layer_L_W_CONFIG00.o \
./src/layer/layer_L_W_CONFIG01.o \
./src/layer/layer_L_W_MODESELECT00.o \
./src/layer/layer_L_W_SETTING00.o \
./src/layer/layer_L_W_SETTING01.o \
./src/layer/layer_L_W_SETTING02.o \
./src/layer/layer_L_W_SETTING03.o 

MAP += \
STYO2225A.map 


# Each subdirectory must supply rules for building sources it contributes
src/layer/%.o: ../src/layer/%.c
	@echo 'Building file: $<'
	$(file > $@.in,-mcpu=cortex-a9 -marm -mlittle-endian -mfloat-abi=hard -mfpu=vfpv3-d16 -fdiagnostics-parseable-fixits -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wnull-dereference -g -gdwarf-4 -I"X:\\GUI\\STYO2225A\\STYO2225A\\src\\mode" -I"X:\\GUI\\STYO2225A\\STYO2225A\\src\\module\\ff" -I"X:/GUI/STYO2225A/STYO2225A/generate" -I"X:/GUI/STYO2225A/STYO2225A/src" -I"X:/GUI/STYO2225A/STYO2225A/src/module" -I"X:/GUI/STYO2225A/STYO2225A/src/inxlib" -I"X:/GUI/STYO2225A/STYO2225A/src/driver/vdc5/inc" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<")
	@arm-none-eabi-gcc @"$@.in"

