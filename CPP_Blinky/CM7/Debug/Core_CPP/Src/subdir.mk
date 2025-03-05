################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Core_CPP/Src/BlinkingLed.cpp \
../Core_CPP/Src/NoneBlockSystemTickDelay.cpp \
../Core_CPP/Src/STM32H7Led.cpp 

OBJS += \
./Core_CPP/Src/BlinkingLed.o \
./Core_CPP/Src/NoneBlockSystemTickDelay.o \
./Core_CPP/Src/STM32H7Led.o 

CPP_DEPS += \
./Core_CPP/Src/BlinkingLed.d \
./Core_CPP/Src/NoneBlockSystemTickDelay.d \
./Core_CPP/Src/STM32H7Led.d 


# Each subdirectory must supply rules for building sources it contributes
Core_CPP/Src/%.o Core_CPP/Src/%.su Core_CPP/Src/%.cyclo: ../Core_CPP/Src/%.cpp Core_CPP/Src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++20 -g3 -DDEBUG -DCORE_CM7 -DUSE_HAL_DRIVER -DSTM32H745xx -c -I../Core/Inc -I../Core_CPP/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core_CPP-2f-Src

clean-Core_CPP-2f-Src:
	-$(RM) ./Core_CPP/Src/BlinkingLed.cyclo ./Core_CPP/Src/BlinkingLed.d ./Core_CPP/Src/BlinkingLed.o ./Core_CPP/Src/BlinkingLed.su ./Core_CPP/Src/NoneBlockSystemTickDelay.cyclo ./Core_CPP/Src/NoneBlockSystemTickDelay.d ./Core_CPP/Src/NoneBlockSystemTickDelay.o ./Core_CPP/Src/NoneBlockSystemTickDelay.su ./Core_CPP/Src/STM32H7Led.cyclo ./Core_CPP/Src/STM32H7Led.d ./Core_CPP/Src/STM32H7Led.o ./Core_CPP/Src/STM32H7Led.su

.PHONY: clean-Core_CPP-2f-Src

