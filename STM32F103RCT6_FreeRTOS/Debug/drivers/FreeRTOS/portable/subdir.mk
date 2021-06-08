################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/FreeRTOS/portable/heap_4.c \
../drivers/FreeRTOS/portable/port.c 

C_DEPS += \
./drivers/FreeRTOS/portable/heap_4.d \
./drivers/FreeRTOS/portable/port.d 

OBJS += \
./drivers/FreeRTOS/portable/heap_4.o \
./drivers/FreeRTOS/portable/port.o 


# Each subdirectory must supply rules for building sources it contributes
drivers/FreeRTOS/portable/heap_4.o: ../drivers/FreeRTOS/portable/heap_4.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -c -I"E:/STM32CubeIDE/workspace_1.4.0/STM32F103RCT6_FreeRTOS/drivers" -I"E:/STM32CubeIDE/workspace_1.4.0/STM32F103RCT6_FreeRTOS/drivers/FreeRTOS/portable" -I"E:/STM32CubeIDE/workspace_1.4.0/STM32F103RCT6_FreeRTOS/drivers/FreeRTOS/CMSIS_RTOS_V2" -I"E:/STM32CubeIDE/workspace_1.4.0/STM32F103RCT6_FreeRTOS/drivers/FreeRTOS/include" -I"E:/STM32CubeIDE/workspace_1.4.0/STM32F103RCT6_FreeRTOS/devices" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"drivers/FreeRTOS/portable/heap_4.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
drivers/FreeRTOS/portable/port.o: ../drivers/FreeRTOS/portable/port.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -c -I"E:/STM32CubeIDE/workspace_1.4.0/STM32F103RCT6_FreeRTOS/drivers" -I"E:/STM32CubeIDE/workspace_1.4.0/STM32F103RCT6_FreeRTOS/drivers/FreeRTOS/portable" -I"E:/STM32CubeIDE/workspace_1.4.0/STM32F103RCT6_FreeRTOS/drivers/FreeRTOS/CMSIS_RTOS_V2" -I"E:/STM32CubeIDE/workspace_1.4.0/STM32F103RCT6_FreeRTOS/drivers/FreeRTOS/include" -I"E:/STM32CubeIDE/workspace_1.4.0/STM32F103RCT6_FreeRTOS/devices" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"drivers/FreeRTOS/portable/port.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

