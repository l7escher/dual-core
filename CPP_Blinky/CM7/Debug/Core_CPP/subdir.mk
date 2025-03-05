################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Core_CPP/BlinkingLed.cpp \
../Core_CPP/NoneBlockSystemTickDelay.cpp \
../Core_CPP/STM32H7Led.cpp 

OBJS += \
./Core_CPP/BlinkingLed.o \
./Core_CPP/NoneBlockSystemTickDelay.o \
./Core_CPP/STM32H7Led.o 

CPP_DEPS += \
./Core_CPP/BlinkingLed.d \
./Core_CPP/NoneBlockSystemTickDelay.d \
./Core_CPP/STM32H7Led.d 


# Each subdirectory must supply rules for building sources it contributes
Core_CPP/%.o Core_CPP/%.su: ../Core_CPP/%.cpp Core_CPP/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++20 -g3 -DDEBUG -DCORE_CM7 -DUSE_HAL_DRIVER -DSTM32H745xx -c -I../Core/Inc -I"C:/Users/muaha/Desktop/FHNW/Master/EmbReal/CPP_Blinky/CM7/Core_CPP/Inc" -I"C:/Users/muaha/Desktop/FHNW/Master/EmbReal/CPP_Blinky/CM7/Core_CPP" -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core_CPP

clean-Core_CPP:
	-$(RM) ./Core_CPP/BlinkingLed.d ./Core_CPP/BlinkingLed.o ./Core_CPP/BlinkingLed.su ./Core_CPP/NoneBlockSystemTickDelay.d ./Core_CPP/NoneBlockSystemTickDelay.o ./Core_CPP/NoneBlockSystemTickDelay.su ./Core_CPP/STM32H7Led.d ./Core_CPP/STM32H7Led.o ./Core_CPP/STM32H7Led.su

.PHONY: clean-Core_CPP

