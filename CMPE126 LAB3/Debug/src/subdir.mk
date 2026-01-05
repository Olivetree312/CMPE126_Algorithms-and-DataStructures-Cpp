################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/CMPE126\ LAB3.cpp 

CPP_DEPS += \
./src/CMPE126\ LAB3.d 

OBJS += \
./src/CMPE126\ LAB3.o 


# Each subdirectory must supply rules for building sources it contributes
src/CMPE126\ LAB3.o: ../src/CMPE126\ LAB3.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++17 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/CMPE126 LAB3.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/CMPE126\ LAB3.d ./src/CMPE126\ LAB3.o

.PHONY: clean-src

