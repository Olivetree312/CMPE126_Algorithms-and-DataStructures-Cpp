################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../CA1.src/Animal.cpp \
../CA1.src/Cat.cpp \
../CA1.src/Dog.cpp \
../CA1.src/main.cpp 

CPP_DEPS += \
./CA1.src/Animal.d \
./CA1.src/Cat.d \
./CA1.src/Dog.d \
./CA1.src/main.d 

OBJS += \
./CA1.src/Animal.o \
./CA1.src/Cat.o \
./CA1.src/Dog.o \
./CA1.src/main.o 


# Each subdirectory must supply rules for building sources it contributes
CA1.src/%.o: ../CA1.src/%.cpp CA1.src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-CA1-2e-src

clean-CA1-2e-src:
	-$(RM) ./CA1.src/Animal.d ./CA1.src/Animal.o ./CA1.src/Cat.d ./CA1.src/Cat.o ./CA1.src/Dog.d ./CA1.src/Dog.o ./CA1.src/main.d ./CA1.src/main.o

.PHONY: clean-CA1-2e-src

