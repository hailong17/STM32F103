################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/FreeRTOS/croutine.c \
../drivers/FreeRTOS/event_groups.c \
../drivers/FreeRTOS/list.c \
../drivers/FreeRTOS/queue.c \
../drivers/FreeRTOS/stream_buffer.c \
../drivers/FreeRTOS/tasks.c \
../drivers/FreeRTOS/timers.c 

C_DEPS += \
./drivers/FreeRTOS/croutine.d \
./drivers/FreeRTOS/event_groups.d \
./drivers/FreeRTOS/list.d \
./drivers/FreeRTOS/queue.d \
./drivers/FreeRTOS/stream_buffer.d \
./drivers/FreeRTOS/tasks.d \
./drivers/FreeRTOS/timers.d 

OBJS += \
./drivers/FreeRTOS/croutine.o \
./drivers/FreeRTOS/event_groups.o \
./drivers/FreeRTOS/list.o \
./drivers/FreeRTOS/queue.o \
./drivers/FreeRTOS/stream_buffer.o \
./drivers/FreeRTOS/tasks.o \
./drivers/FreeRTOS/timers.o 


# Each subdirectory must supply rules for building sources it contributes
drivers/FreeRTOS/croutine.o: ../drivers/FreeRTOS/croutine.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -c -I"E:/STM32CubeIDE/workspace_1.4.0/STM32F103RCT6_FreeRTOS/drivers" -I"E:/STM32CubeIDE/workspace_1.4.0/STM32F103RCT6_FreeRTOS/drivers/FreeRTOS/portable" -I"E:/STM32CubeIDE/workspace_1.4.0/STM32F103RCT6_FreeRTOS/drivers/FreeRTOS/CMSIS_RTOS_V2" -I"E:/STM32CubeIDE/workspace_1.4.0/STM32F103RCT6_FreeRTOS/drivers/FreeRTOS/include" -I"E:/STM32CubeIDE/workspace_1.4.0/STM32F103RCT6_FreeRTOS/devices" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"drivers/FreeRTOS/croutine.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
drivers/FreeRTOS/event_groups.o: ../drivers/FreeRTOS/event_groups.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -c -I"E:/STM32CubeIDE/workspace_1.4.0/STM32F103RCT6_FreeRTOS/drivers" -I"E:/STM32CubeIDE/workspace_1.4.0/STM32F103RCT6_FreeRTOS/drivers/FreeRTOS/portable" -I"E:/STM32CubeIDE/workspace_1.4.0/STM32F103RCT6_FreeRTOS/drivers/FreeRTOS/CMSIS_RTOS_V2" -I"E:/STM32CubeIDE/workspace_1.4.0/STM32F103RCT6_FreeRTOS/drivers/FreeRTOS/include" -I"E:/STM32CubeIDE/workspace_1.4.0/STM32F103RCT6_FreeRTOS/devices" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"drivers/FreeRTOS/event_groups.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
drivers/FreeRTOS/list.o: ../drivers/FreeRTOS/list.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -c -I"E:/STM32CubeIDE/workspace_1.4.0/STM32F103RCT6_FreeRTOS/drivers" -I"E:/STM32CubeIDE/workspace_1.4.0/STM32F103RCT6_FreeRTOS/drivers/FreeRTOS/portable" -I"E:/STM32CubeIDE/workspace_1.4.0/STM32F103RCT6_FreeRTOS/drivers/FreeRTOS/CMSIS_RTOS_V2" -I"E:/STM32CubeIDE/workspace_1.4.0/STM32F103RCT6_FreeRTOS/drivers/FreeRTOS/include" -I"E:/STM32CubeIDE/workspace_1.4.0/STM32F103RCT6_FreeRTOS/devices" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"drivers/FreeRTOS/list.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
drivers/FreeRTOS/queue.o: ../drivers/FreeRTOS/queue.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -c -I"E:/STM32CubeIDE/workspace_1.4.0/STM32F103RCT6_FreeRTOS/drivers" -I"E:/STM32CubeIDE/workspace_1.4.0/STM32F103RCT6_FreeRTOS/drivers/FreeRTOS/portable" -I"E:/STM32CubeIDE/workspace_1.4.0/STM32F103RCT6_FreeRTOS/drivers/FreeRTOS/CMSIS_RTOS_V2" -I"E:/STM32CubeIDE/workspace_1.4.0/STM32F103RCT6_FreeRTOS/drivers/FreeRTOS/include" -I"E:/STM32CubeIDE/workspace_1.4.0/STM32F103RCT6_FreeRTOS/devices" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"drivers/FreeRTOS/queue.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
drivers/FreeRTOS/stream_buffer.o: ../drivers/FreeRTOS/stream_buffer.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -c -I"E:/STM32CubeIDE/workspace_1.4.0/STM32F103RCT6_FreeRTOS/drivers" -I"E:/STM32CubeIDE/workspace_1.4.0/STM32F103RCT6_FreeRTOS/drivers/FreeRTOS/portable" -I"E:/STM32CubeIDE/workspace_1.4.0/STM32F103RCT6_FreeRTOS/drivers/FreeRTOS/CMSIS_RTOS_V2" -I"E:/STM32CubeIDE/workspace_1.4.0/STM32F103RCT6_FreeRTOS/drivers/FreeRTOS/include" -I"E:/STM32CubeIDE/workspace_1.4.0/STM32F103RCT6_FreeRTOS/devices" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"drivers/FreeRTOS/stream_buffer.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
drivers/FreeRTOS/tasks.o: ../drivers/FreeRTOS/tasks.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -c -I"E:/STM32CubeIDE/workspace_1.4.0/STM32F103RCT6_FreeRTOS/drivers" -I"E:/STM32CubeIDE/workspace_1.4.0/STM32F103RCT6_FreeRTOS/drivers/FreeRTOS/portable" -I"E:/STM32CubeIDE/workspace_1.4.0/STM32F103RCT6_FreeRTOS/drivers/FreeRTOS/CMSIS_RTOS_V2" -I"E:/STM32CubeIDE/workspace_1.4.0/STM32F103RCT6_FreeRTOS/drivers/FreeRTOS/include" -I"E:/STM32CubeIDE/workspace_1.4.0/STM32F103RCT6_FreeRTOS/devices" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"drivers/FreeRTOS/tasks.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
drivers/FreeRTOS/timers.o: ../drivers/FreeRTOS/timers.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -c -I"E:/STM32CubeIDE/workspace_1.4.0/STM32F103RCT6_FreeRTOS/drivers" -I"E:/STM32CubeIDE/workspace_1.4.0/STM32F103RCT6_FreeRTOS/drivers/FreeRTOS/portable" -I"E:/STM32CubeIDE/workspace_1.4.0/STM32F103RCT6_FreeRTOS/drivers/FreeRTOS/CMSIS_RTOS_V2" -I"E:/STM32CubeIDE/workspace_1.4.0/STM32F103RCT6_FreeRTOS/drivers/FreeRTOS/include" -I"E:/STM32CubeIDE/workspace_1.4.0/STM32F103RCT6_FreeRTOS/devices" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"drivers/FreeRTOS/timers.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

