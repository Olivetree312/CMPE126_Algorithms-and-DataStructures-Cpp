################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../LAB5.src/linkedList.cpp \
../LAB5.src/main.cpp \
../LAB5.src/perrin.cpp \
../LAB5.src/setbitcount.cpp 

CPP_DEPS += \
./LAB5.src/linkedList.d \
./LAB5.src/main.d \
./LAB5.src/perrin.d \
./LAB5.src/setbitcount.d 

OBJS += \
./LAB5.src/linkedList.o \
./LAB5.src/main.o \
./LAB5.src/perrin.o \
./LAB5.src/setbitcount.o 


# Each subdirectory must supply rules for building sources it contributes
LAB5.src/%.o: ../LAB5.src/%.cpp LAB5.src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-LAB5-2e-src

clean-LAB5-2e-src:
	-$(RM) ./LAB5.src/linkedList.d ./LAB5.src/linkedList.o ./LAB5.src/main.d ./LAB5.src/main.o ./LAB5.src/perrin.d ./LAB5.src/perrin.o ./LAB5.src/setbitcount.d ./LAB5.src/setbitcount.o

.PHONY: clean-LAB5-2e-src

