################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Project_Setting/StartupCode/startup_stm32f103rctx.s 

S_DEPS += \
./Project_Setting/StartupCode/startup_stm32f103rctx.d 

OBJS += \
./Project_Setting/StartupCode/startup_stm32f103rctx.o 


# Each subdirectory must supply rules for building sources it contributes
Project_Setting/StartupCode/startup_stm32f103rctx.o: ../Project_Setting/StartupCode/startup_stm32f103rctx.s
	arm-none-eabi-gcc -mcpu=cortex-m3 -g3 -c -x assembler-with-cpp -MMD -MP -MF"Project_Setting/StartupCode/startup_stm32f103rctx.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@" "$<"

