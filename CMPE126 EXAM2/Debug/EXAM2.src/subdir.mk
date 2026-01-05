################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../EXAM2.src/Robot.cpp \
../EXAM2.src/main.cpp \
../EXAM2.src/sumHex.cpp 

CPP_DEPS += \
./EXAM2.src/Robot.d \
./EXAM2.src/main.d \
./EXAM2.src/sumHex.d 

OBJS += \
./EXAM2.src/Robot.o \
./EXAM2.src/main.o \
./EXAM2.src/sumHex.o 


# Each subdirectory must supply rules for building sources it contributes
EXAM2.src/%.o: ../EXAM2.src/%.cpp EXAM2.src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-EXAM2-2e-src

clean-EXAM2-2e-src:
	-$(RM) ./EXAM2.src/Robot.d ./EXAM2.src/Robot.o ./EXAM2.src/main.d ./EXAM2.src/main.o ./EXAM2.src/sumHex.d ./EXAM2.src/sumHex.o

.PHONY: clean-EXAM2-2e-src

