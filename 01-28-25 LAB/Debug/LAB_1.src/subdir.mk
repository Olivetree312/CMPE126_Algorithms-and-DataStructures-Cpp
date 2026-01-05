################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../LAB_1.src/CMPE126_LAB1.cpp 

CPP_DEPS += \
./LAB_1.src/CMPE126_LAB1.d 

OBJS += \
./LAB_1.src/CMPE126_LAB1.o 


# Each subdirectory must supply rules for building sources it contributes
LAB_1.src/%.o: ../LAB_1.src/%.cpp LAB_1.src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-LAB_1-2e-src

clean-LAB_1-2e-src:
	-$(RM) ./LAB_1.src/CMPE126_LAB1.d ./LAB_1.src/CMPE126_LAB1.o

.PHONY: clean-LAB_1-2e-src

