################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/hw_settings/adc_portsetting.c \
../src/hw_settings/cpu_clock_setting.c \
../src/hw_settings/scif_portsetting.c \
../src/hw_settings/timer_setting.c \
../src/hw_settings/vdc5_portsetting.c 

LST += \
adc_portsetting.lst \
cpu_clock_setting.lst \
scif_portsetting.lst \
timer_setting.lst \
vdc5_portsetting.lst 

C_DEPS += \
./src/hw_settings/adc_portsetting.d \
./src/hw_settings/cpu_clock_setting.d \
./src/hw_settings/scif_portsetting.d \
./src/hw_settings/timer_setting.d \
./src/hw_settings/vdc5_portsetting.d 

OBJS += \
./src/hw_settings/adc_portsetting.o \
./src/hw_settings/cpu_clock_setting.o \
./src/hw_settings/scif_portsetting.o \
./src/hw_settings/timer_setting.o \
./src/hw_settings/vdc5_portsetting.o 

MAP += \
STYO2225A.map 


# Each subdirectory must supply rules for building sources it contributes
src/hw_settings/%.o: ../src/hw_settings/%.c
	@echo 'Building file: $<'
	$(file > $@.in,-mcpu=cortex-a9 -marm -mlittle-endian -mfloat-abi=hard -mfpu=vfpv3-d16 -fdiagnostics-parseable-fixits -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wnull-dereference -g -gdwarf-4 -I"X:\\GUI\\STYO2225A\\STYO2225A\\src\\mode" -I"X:\\GUI\\STYO2225A\\STYO2225A\\src\\module\\ff" -I"X:/GUI/STYO2225A/STYO2225A/generate" -I"X:/GUI/STYO2225A/STYO2225A/src" -I"X:/GUI/STYO2225A/STYO2225A/src/module" -I"X:/GUI/STYO2225A/STYO2225A/src/inxlib" -I"X:/GUI/STYO2225A/STYO2225A/src/driver/vdc5/inc" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<")
	@arm-none-eabi-gcc @"$@.in"

