################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../drivers/LED7seg.cpp \
../drivers/RF315.cpp 

OBJS += \
./drivers/LED7seg.o \
./drivers/RF315.o 

CPP_DEPS += \
./drivers/LED7seg.d \
./drivers/RF315.d 


# Each subdirectory must supply rules for building sources it contributes
drivers/LED7seg.o: ../drivers/LED7seg.cpp
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DDEBUG -c -I"E:/STM32CubeIDE/workspace_1.4.0/STM32F103RCT6_FreeRTOS/drivers" -I"E:/STM32CubeIDE/workspace_1.4.0/STM32F103RCT6_FreeRTOS/drivers/FreeRTOS/portable" -I"E:/STM32CubeIDE/workspace_1.4.0/STM32F103RCT6_FreeRTOS/drivers/FreeRTOS/CMSIS_RTOS_V2" -I"E:/STM32CubeIDE/workspace_1.4.0/STM32F103RCT6_FreeRTOS/drivers/FreeRTOS/include" -I"E:/STM32CubeIDE/workspace_1.4.0/STM32F103RCT6_FreeRTOS/devices" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-threadsafe-statics -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"drivers/LED7seg.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
drivers/RF315.o: ../drivers/RF315.cpp
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DDEBUG -c -I"E:/STM32CubeIDE/workspace_1.4.0/STM32F103RCT6_FreeRTOS/drivers" -I"E:/STM32CubeIDE/workspace_1.4.0/STM32F103RCT6_FreeRTOS/drivers/FreeRTOS/portable" -I"E:/STM32CubeIDE/workspace_1.4.0/STM32F103RCT6_FreeRTOS/drivers/FreeRTOS/CMSIS_RTOS_V2" -I"E:/STM32CubeIDE/workspace_1.4.0/STM32F103RCT6_FreeRTOS/drivers/FreeRTOS/include" -I"E:/STM32CubeIDE/workspace_1.4.0/STM32F103RCT6_FreeRTOS/devices" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-threadsafe-statics -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"drivers/RF315.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

