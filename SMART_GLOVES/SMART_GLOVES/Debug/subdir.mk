################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC_program.c \
../DIO_program.c \
../LCD_program.c \
../SENSOR_program.c \
../gloves_Prog.c \
../main.c 

OBJS += \
./ADC_program.o \
./DIO_program.o \
./LCD_program.o \
./SENSOR_program.o \
./gloves_Prog.o \
./main.o 

C_DEPS += \
./ADC_program.d \
./DIO_program.d \
./LCD_program.d \
./SENSOR_program.d \
./gloves_Prog.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


