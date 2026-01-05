################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../CMPE126_LAB.src/DateOfBirth.cpp \
../CMPE126_LAB.src/Flight.cpp \
../CMPE126_LAB.src/Passenger.cpp \
../CMPE126_LAB.src/Ticket.cpp \
../CMPE126_LAB.src/Time.cpp \
../CMPE126_LAB.src/lab2-cmpe126.cpp 

CPP_DEPS += \
./CMPE126_LAB.src/DateOfBirth.d \
./CMPE126_LAB.src/Flight.d \
./CMPE126_LAB.src/Passenger.d \
./CMPE126_LAB.src/Ticket.d \
./CMPE126_LAB.src/Time.d \
./CMPE126_LAB.src/lab2-cmpe126.d 

OBJS += \
./CMPE126_LAB.src/DateOfBirth.o \
./CMPE126_LAB.src/Flight.o \
./CMPE126_LAB.src/Passenger.o \
./CMPE126_LAB.src/Ticket.o \
./CMPE126_LAB.src/Time.o \
./CMPE126_LAB.src/lab2-cmpe126.o 


# Each subdirectory must supply rules for building sources it contributes
CMPE126_LAB.src/DateOfBirth.o: ../CMPE126_LAB.src/DateOfBirth.cpp CMPE126_LAB.src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

CMPE126_LAB.src/%.o: ../CMPE126_LAB.src/%.cpp CMPE126_LAB.src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-CMPE126_LAB-2e-src

clean-CMPE126_LAB-2e-src:
	-$(RM) ./CMPE126_LAB.src/DateOfBirth.d ./CMPE126_LAB.src/DateOfBirth.o ./CMPE126_LAB.src/Flight.d ./CMPE126_LAB.src/Flight.o ./CMPE126_LAB.src/Passenger.d ./CMPE126_LAB.src/Passenger.o ./CMPE126_LAB.src/Ticket.d ./CMPE126_LAB.src/Ticket.o ./CMPE126_LAB.src/Time.d ./CMPE126_LAB.src/Time.o ./CMPE126_LAB.src/lab2-cmpe126.d ./CMPE126_LAB.src/lab2-cmpe126.o

.PHONY: clean-CMPE126_LAB-2e-src

