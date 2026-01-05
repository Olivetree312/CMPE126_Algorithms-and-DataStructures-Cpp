################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../2-6-25_LEC.src/main.cpp 

CPP_DEPS += \
./2-6-25_LEC.src/main.d 

OBJS += \
./2-6-25_LEC.src/main.o 


# Each subdirectory must supply rules for building sources it contributes
2-6-25_LEC.src/%.o: ../2-6-25_LEC.src/%.cpp 2-6-25_LEC.src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-2-2d-6-2d-25_LEC-2e-src

clean-2-2d-6-2d-25_LEC-2e-src:
	-$(RM) ./2-6-25_LEC.src/main.d ./2-6-25_LEC.src/main.o

.PHONY: clean-2-2d-6-2d-25_LEC-2e-src

