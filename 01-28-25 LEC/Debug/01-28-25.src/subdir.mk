################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../01-28-25.src/01-28-25_LEC.cpp 

CPP_DEPS += \
./01-28-25.src/01-28-25_LEC.d 

OBJS += \
./01-28-25.src/01-28-25_LEC.o 


# Each subdirectory must supply rules for building sources it contributes
01-28-25.src/%.o: ../01-28-25.src/%.cpp 01-28-25.src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-01-2d-28-2d-25-2e-src

clean-01-2d-28-2d-25-2e-src:
	-$(RM) ./01-28-25.src/01-28-25_LEC.d ./01-28-25.src/01-28-25_LEC.o

.PHONY: clean-01-2d-28-2d-25-2e-src

