################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Calculator_Priviliges.c \
../DIO_previliges.c \
../KeyPad_Priviliges.c \
../LCD_prog.c \
../main.c 

OBJS += \
./Calculator_Priviliges.o \
./DIO_previliges.o \
./KeyPad_Priviliges.o \
./LCD_prog.o \
./main.o 

C_DEPS += \
./Calculator_Priviliges.d \
./DIO_previliges.d \
./KeyPad_Priviliges.d \
./LCD_prog.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


