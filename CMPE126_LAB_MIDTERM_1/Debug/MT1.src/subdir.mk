################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../MT1.src/Baby.cpp \
../MT1.src/Dosage.cpp \
../MT1.src/Weight.cpp \
../MT1.src/progExam1.cpp 

CPP_DEPS += \
./MT1.src/Baby.d \
./MT1.src/Dosage.d \
./MT1.src/Weight.d \
./MT1.src/progExam1.d 

OBJS += \
./MT1.src/Baby.o \
./MT1.src/Dosage.o \
./MT1.src/Weight.o \
./MT1.src/progExam1.o 


# Each subdirectory must supply rules for building sources it contributes
MT1.src/%.o: ../MT1.src/%.cpp MT1.src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-MT1-2e-src

clean-MT1-2e-src:
	-$(RM) ./MT1.src/Baby.d ./MT1.src/Baby.o ./MT1.src/Dosage.d ./MT1.src/Dosage.o ./MT1.src/Weight.d ./MT1.src/Weight.o ./MT1.src/progExam1.d ./MT1.src/progExam1.o

.PHONY: clean-MT1-2e-src

