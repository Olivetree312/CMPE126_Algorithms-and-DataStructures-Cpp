################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../LAB4.src/lab4-cmpe126.cpp \
../LAB4.src/linkedList.cpp 

CPP_DEPS += \
./LAB4.src/lab4-cmpe126.d \
./LAB4.src/linkedList.d 

OBJS += \
./LAB4.src/lab4-cmpe126.o \
./LAB4.src/linkedList.o 


# Each subdirectory must supply rules for building sources it contributes
LAB4.src/%.o: ../LAB4.src/%.cpp LAB4.src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-LAB4-2e-src

clean-LAB4-2e-src:
	-$(RM) ./LAB4.src/lab4-cmpe126.d ./LAB4.src/lab4-cmpe126.o ./LAB4.src/linkedList.d ./LAB4.src/linkedList.o

.PHONY: clean-LAB4-2e-src

