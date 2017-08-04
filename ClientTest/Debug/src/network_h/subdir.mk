################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/network_h/JSONHandler.cpp \
../src/network_h/NetworkHandler.cpp \
../src/network_h/Reader.cpp 

OBJS += \
./src/network_h/JSONHandler.o \
./src/network_h/NetworkHandler.o \
./src/network_h/Reader.o 

CPP_DEPS += \
./src/network_h/JSONHandler.d \
./src/network_h/NetworkHandler.d \
./src/network_h/Reader.d 


# Each subdirectory must supply rules for building sources it contributes
src/network_h/%.o: ../src/network_h/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/home/marcelo/Documents/libs/rapidjson/include/ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


