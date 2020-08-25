################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../NetworkStudent.cpp \
../Roster.cpp \
../SecurityStudent.cpp \
../SoftwareStudent.cpp \
../Student.cpp 

OBJS += \
./NetworkStudent.o \
./Roster.o \
./SecurityStudent.o \
./SoftwareStudent.o \
./Student.o 

CPP_DEPS += \
./NetworkStudent.d \
./Roster.d \
./SecurityStudent.d \
./SoftwareStudent.d \
./Student.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


