################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/os/delegate.c \
../src/os/intc.c 

C_DEPS += \
./src/os/delegate.d \
./src/os/intc.d 

OBJS += \
./src/os/delegate.o \
./src/os/intc.o 


# Each subdirectory must supply rules for building sources it contributes
src/os/%.o: ../src/os/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-a9 -march=armv7-a -marm -mlittle-endian -mfloat-abi=hard -mfpu=vfpv3-d16 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wnull-dereference -g -Wstack-usage=500 -I"D:\Project\STYO\STYO2225A\STYO2225A\src\mode" -I"D:\Project\STYO\STYO2225A\STYO2225A\src\module\ff" -I"D:/Project/STYO/STYO2225A/STYO2225A/generate" -I"D:/Project/STYO/STYO2225A/STYO2225A/src" -I"D:/Project/STYO/STYO2225A/STYO2225A/src/module" -I"D:/Project/STYO/STYO2225A/STYO2225A/src/inxlib" -I"D:/Project/STYO/STYO2225A/STYO2225A/src/driver/vdc5/inc" -std=gnu11 -Wstrict-prototypes -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


