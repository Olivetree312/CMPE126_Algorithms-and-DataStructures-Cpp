################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../RPG_Classes_Project.src/Character.cpp \
../RPG_Classes_Project.src/main.cpp 

CPP_DEPS += \
./RPG_Classes_Project.src/Character.d \
./RPG_Classes_Project.src/main.d 

OBJS += \
./RPG_Classes_Project.src/Character.o \
./RPG_Classes_Project.src/main.o 


# Each subdirectory must supply rules for building sources it contributes
RPG_Classes_Project.src/%.o: ../RPG_Classes_Project.src/%.cpp RPG_Classes_Project.src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++1y -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-RPG_Classes_Project-2e-src

clean-RPG_Classes_Project-2e-src:
	-$(RM) ./RPG_Classes_Project.src/Character.d ./RPG_Classes_Project.src/Character.o ./RPG_Classes_Project.src/main.d ./RPG_Classes_Project.src/main.o

.PHONY: clean-RPG_Classes_Project-2e-src

