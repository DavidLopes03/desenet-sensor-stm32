################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
E:/DeSem/Projet/desenet-work/work/desenet-sensor/src/common/platform/nucleo-stm32l476rg/mcu/hal/spi.cpp \
E:/DeSem/Projet/desenet-work/work/desenet-sensor/src/common/platform/nucleo-stm32l476rg/mcu/hal/uart.cpp 

OBJS += \
./desenet-common/platform/nucleo-stm32l476rg/mcu/hal/spi.o \
./desenet-common/platform/nucleo-stm32l476rg/mcu/hal/uart.o 

CPP_DEPS += \
./desenet-common/platform/nucleo-stm32l476rg/mcu/hal/spi.d \
./desenet-common/platform/nucleo-stm32l476rg/mcu/hal/uart.d 


# Each subdirectory must supply rules for building sources it contributes
desenet-common/platform/nucleo-stm32l476rg/mcu/hal/spi.o: E:/DeSem/Projet/desenet-work/work/desenet-sensor/src/common/platform/nucleo-stm32l476rg/mcu/hal/spi.cpp desenet-common/platform/nucleo-stm32l476rg/mcu/hal/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -DIDE_STM32CUBEIDE -DTC_STM32CUBEIDE -DUSE_DISPLAY -DDISPLAY_DRIVER_SSD1608 -c -I"E:/DeSem/Projet/desenet-work/work/desenet-sensor/ide-stm32cubeide/.." -I"E:/DeSem/Projet/desenet-work/work/desenet-sensor/ide-stm32cubeide/../src" -I"E:/DeSem/Projet/desenet-work/work/desenet-sensor/ide-stm32cubeide/platform/nucleo-stm32l476rg" -I"E:/DeSem/Projet/desenet-work/work/desenet-sensor/src/common/platform/nucleo-stm32l476rg" -I"E:/DeSem/Projet/desenet-work/work/desenet-sensor/src/common/platform/nucleo-stm32l476rg/mcu" -I"E:/DeSem/Projet/desenet-work/work/desenet-sensor/src/common/platform/nucleo-stm32l476rg/board" -I"E:/DeSem/Projet/desenet-work/work/desenet-sensor/src/common/platform/platform-common" -I"E:/DeSem/Projet/desenet-work/work/desenet-sensor/src/common/platform/platform-common/board" -I"E:/DeSem/Projet/desenet-work/work/desenet-sensor/src/common/platform" -I"E:/DeSem/Projet/desenet-work/work/desenet-sensor/src/common/mdw" -I"E:/DeSem/Projet/desenet-work/work/desenet-sensor/src/common/mdw/desenet" -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
desenet-common/platform/nucleo-stm32l476rg/mcu/hal/uart.o: E:/DeSem/Projet/desenet-work/work/desenet-sensor/src/common/platform/nucleo-stm32l476rg/mcu/hal/uart.cpp desenet-common/platform/nucleo-stm32l476rg/mcu/hal/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -DIDE_STM32CUBEIDE -DTC_STM32CUBEIDE -DUSE_DISPLAY -DDISPLAY_DRIVER_SSD1608 -c -I"E:/DeSem/Projet/desenet-work/work/desenet-sensor/ide-stm32cubeide/.." -I"E:/DeSem/Projet/desenet-work/work/desenet-sensor/ide-stm32cubeide/../src" -I"E:/DeSem/Projet/desenet-work/work/desenet-sensor/ide-stm32cubeide/platform/nucleo-stm32l476rg" -I"E:/DeSem/Projet/desenet-work/work/desenet-sensor/src/common/platform/nucleo-stm32l476rg" -I"E:/DeSem/Projet/desenet-work/work/desenet-sensor/src/common/platform/nucleo-stm32l476rg/mcu" -I"E:/DeSem/Projet/desenet-work/work/desenet-sensor/src/common/platform/nucleo-stm32l476rg/board" -I"E:/DeSem/Projet/desenet-work/work/desenet-sensor/src/common/platform/platform-common" -I"E:/DeSem/Projet/desenet-work/work/desenet-sensor/src/common/platform/platform-common/board" -I"E:/DeSem/Projet/desenet-work/work/desenet-sensor/src/common/platform" -I"E:/DeSem/Projet/desenet-work/work/desenet-sensor/src/common/mdw" -I"E:/DeSem/Projet/desenet-work/work/desenet-sensor/src/common/mdw/desenet" -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-desenet-2d-common-2f-platform-2f-nucleo-2d-stm32l476rg-2f-mcu-2f-hal

clean-desenet-2d-common-2f-platform-2f-nucleo-2d-stm32l476rg-2f-mcu-2f-hal:
	-$(RM) ./desenet-common/platform/nucleo-stm32l476rg/mcu/hal/spi.cyclo ./desenet-common/platform/nucleo-stm32l476rg/mcu/hal/spi.d ./desenet-common/platform/nucleo-stm32l476rg/mcu/hal/spi.o ./desenet-common/platform/nucleo-stm32l476rg/mcu/hal/spi.su ./desenet-common/platform/nucleo-stm32l476rg/mcu/hal/uart.cyclo ./desenet-common/platform/nucleo-stm32l476rg/mcu/hal/uart.d ./desenet-common/platform/nucleo-stm32l476rg/mcu/hal/uart.o ./desenet-common/platform/nucleo-stm32l476rg/mcu/hal/uart.su

.PHONY: clean-desenet-2d-common-2f-platform-2f-nucleo-2d-stm32l476rg-2f-mcu-2f-hal

