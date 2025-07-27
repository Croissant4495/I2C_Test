################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC_Program.c \
../DIO_Program.c \
../EXTINT_Program.c \
../GIE_Program.c \
../TWI_prog.c \
../main.c 

OBJS += \
./ADC_Program.o \
./DIO_Program.o \
./EXTINT_Program.o \
./GIE_Program.o \
./TWI_prog.o \
./main.o 

C_DEPS += \
./ADC_Program.d \
./DIO_Program.d \
./EXTINT_Program.d \
./GIE_Program.d \
./TWI_prog.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


