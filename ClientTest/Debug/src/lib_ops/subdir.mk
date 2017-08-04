################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/lib_ops/RMlib.cpp \
../src/lib_ops/rmRefh.cpp 

OBJS += \
./src/lib_ops/RMlib.o \
./src/lib_ops/rmRefh.o 

CPP_DEPS += \
./src/lib_ops/RMlib.d \
./src/lib_ops/rmRefh.d 


# Each subdirectory must supply rules for building sources it contributes
src/lib_ops/%.o: ../src/lib_ops/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/home/marcelo/Documents/libs/rapidjson/include/ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


