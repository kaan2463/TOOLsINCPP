################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/data_structure/List.cpp \
../src/data_structure/MergeSort.cpp 

OBJS += \
./src/data_structure/List.o \
./src/data_structure/MergeSort.o 

CPP_DEPS += \
./src/data_structure/List.d \
./src/data_structure/MergeSort.d 


# Each subdirectory must supply rules for building sources it contributes
src/data_structure/%.o: ../src/data_structure/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


