################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/system_stm32f1xx.c 

CPP_SRCS += \
../source/main.cpp 

C_DEPS += \
./source/system_stm32f1xx.d 

OBJS += \
./source/main.o \
./source/system_stm32f1xx.o 

CPP_DEPS += \
./source/main.d 


# Each subdirectory must supply rules for building sources it contributes
source/main.o: ../source/main.cpp
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DDEBUG -c -I"E:/STM32CubeIDE/workspace_1.4.0/STM32F103RCT6_FreeRTOS/drivers" -I"E:/STM32CubeIDE/workspace_1.4.0/STM32F103RCT6_FreeRTOS/drivers/FreeRTOS/portable" -I"E:/STM32CubeIDE/workspace_1.4.0/STM32F103RCT6_FreeRTOS/drivers/FreeRTOS/CMSIS_RTOS_V2" -I"E:/STM32CubeIDE/workspace_1.4.0/STM32F103RCT6_FreeRTOS/drivers/FreeRTOS/include" -I"E:/STM32CubeIDE/workspace_1.4.0/STM32F103RCT6_FreeRTOS/devices" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-threadsafe-statics -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"source/main.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
source/system_stm32f1xx.o: ../source/system_stm32f1xx.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -c -I"E:/STM32CubeIDE/workspace_1.4.0/STM32F103RCT6_FreeRTOS/drivers" -I"E:/STM32CubeIDE/workspace_1.4.0/STM32F103RCT6_FreeRTOS/drivers/FreeRTOS/portable" -I"E:/STM32CubeIDE/workspace_1.4.0/STM32F103RCT6_FreeRTOS/drivers/FreeRTOS/CMSIS_RTOS_V2" -I"E:/STM32CubeIDE/workspace_1.4.0/STM32F103RCT6_FreeRTOS/drivers/FreeRTOS/include" -I"E:/STM32CubeIDE/workspace_1.4.0/STM32F103RCT6_FreeRTOS/devices" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"source/system_stm32f1xx.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

