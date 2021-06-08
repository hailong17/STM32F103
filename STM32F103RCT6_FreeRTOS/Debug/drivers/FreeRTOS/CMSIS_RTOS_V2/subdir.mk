################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/FreeRTOS/CMSIS_RTOS_V2/cmsis_os2.c 

C_DEPS += \
./drivers/FreeRTOS/CMSIS_RTOS_V2/cmsis_os2.d 

OBJS += \
./drivers/FreeRTOS/CMSIS_RTOS_V2/cmsis_os2.o 


# Each subdirectory must supply rules for building sources it contributes
drivers/FreeRTOS/CMSIS_RTOS_V2/cmsis_os2.o: ../drivers/FreeRTOS/CMSIS_RTOS_V2/cmsis_os2.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -c -I"E:/STM32CubeIDE/workspace_1.4.0/STM32F103RCT6_FreeRTOS/drivers" -I"E:/STM32CubeIDE/workspace_1.4.0/STM32F103RCT6_FreeRTOS/drivers/FreeRTOS/portable" -I"E:/STM32CubeIDE/workspace_1.4.0/STM32F103RCT6_FreeRTOS/drivers/FreeRTOS/CMSIS_RTOS_V2" -I"E:/STM32CubeIDE/workspace_1.4.0/STM32F103RCT6_FreeRTOS/drivers/FreeRTOS/include" -I"E:/STM32CubeIDE/workspace_1.4.0/STM32F103RCT6_FreeRTOS/devices" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"drivers/FreeRTOS/CMSIS_RTOS_V2/cmsis_os2.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

