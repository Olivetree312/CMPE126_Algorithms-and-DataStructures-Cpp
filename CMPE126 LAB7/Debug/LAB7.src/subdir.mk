################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../LAB7.src/main.cpp 

CPP_DEPS += \
./LAB7.src/main.d 

OBJS += \
./LAB7.src/main.o 


# Each subdirectory must supply rules for building sources it contributes
LAB7.src/%.o: ../LAB7.src/%.cpp LAB7.src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-LAB7-2e-src

clean-LAB7-2e-src:
	-$(RM) ./LAB7.src/main.d ./LAB7.src/main.o

.PHONY: clean-LAB7-2e-src

