################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../LAB8.src/linkedList.cpp \
../LAB8.src/main.cpp 

CPP_DEPS += \
./LAB8.src/linkedList.d \
./LAB8.src/main.d 

OBJS += \
./LAB8.src/linkedList.o \
./LAB8.src/main.o 


# Each subdirectory must supply rules for building sources it contributes
LAB8.src/%.o: ../LAB8.src/%.cpp LAB8.src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-LAB8-2e-src

clean-LAB8-2e-src:
	-$(RM) ./LAB8.src/linkedList.d ./LAB8.src/linkedList.o ./LAB8.src/main.d ./LAB8.src/main.o

.PHONY: clean-LAB8-2e-src

