################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../CMPE126_LAB3_LP.src/arrayList.cpp \
../CMPE126_LAB3_LP.src/lab3-cmpe126.cpp 

CPP_DEPS += \
./CMPE126_LAB3_LP.src/arrayList.d \
./CMPE126_LAB3_LP.src/lab3-cmpe126.d 

OBJS += \
./CMPE126_LAB3_LP.src/arrayList.o \
./CMPE126_LAB3_LP.src/lab3-cmpe126.o 


# Each subdirectory must supply rules for building sources it contributes
CMPE126_LAB3_LP.src/%.o: ../CMPE126_LAB3_LP.src/%.cpp CMPE126_LAB3_LP.src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-CMPE126_LAB3_LP-2e-src

clean-CMPE126_LAB3_LP-2e-src:
	-$(RM) ./CMPE126_LAB3_LP.src/arrayList.d ./CMPE126_LAB3_LP.src/arrayList.o ./CMPE126_LAB3_LP.src/lab3-cmpe126.d ./CMPE126_LAB3_LP.src/lab3-cmpe126.o

.PHONY: clean-CMPE126_LAB3_LP-2e-src

