################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
E:/DeSem/Projet/desenet-work/work/desenet-sensor/src/common/mdw/clockwork/clockwork.cpp \
E:/DeSem/Projet/desenet-work/work/desenet-sensor/src/common/mdw/clockwork/ttime.cpp 

OBJS += \
./desenet-common/mdw/clockwork/clockwork.o \
./desenet-common/mdw/clockwork/ttime.o 

CPP_DEPS += \
./desenet-common/mdw/clockwork/clockwork.d \
./desenet-common/mdw/clockwork/ttime.d 


# Each subdirectory must supply rules for building sources it contributes
desenet-common/mdw/clockwork/clockwork.o: E:/DeSem/Projet/desenet-work/work/desenet-sensor/src/common/mdw/clockwork/clockwork.cpp desenet-common/mdw/clockwork/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -DIDE_STM32CUBEIDE -DTC_STM32CUBEIDE -DUSE_DISPLAY -DDISPLAY_DRIVER_SSD1608 -c -I"E:/DeSem/Projet/desenet-work/work/desenet-sensor/ide-stm32cubeide/.." -I"E:/DeSem/Projet/desenet-work/work/desenet-sensor/ide-stm32cubeide/../src" -I"E:/DeSem/Projet/desenet-work/work/desenet-sensor/ide-stm32cubeide/platform/nucleo-stm32l476rg" -I"E:/DeSem/Projet/desenet-work/work/desenet-sensor/src/common/platform/nucleo-stm32l476rg" -I"E:/DeSem/Projet/desenet-work/work/desenet-sensor/src/common/platform/nucleo-stm32l476rg/mcu" -I"E:/DeSem/Projet/desenet-work/work/desenet-sensor/src/common/platform/nucleo-stm32l476rg/board" -I"E:/DeSem/Projet/desenet-work/work/desenet-sensor/src/common/platform/platform-common" -I"E:/DeSem/Projet/desenet-work/work/desenet-sensor/src/common/platform/platform-common/board" -I"E:/DeSem/Projet/desenet-work/work/desenet-sensor/src/common/platform" -I"E:/DeSem/Projet/desenet-work/work/desenet-sensor/src/common/mdw" -I"E:/DeSem/Projet/desenet-work/work/desenet-sensor/src/common/mdw/desenet" -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
desenet-common/mdw/clockwork/ttime.o: E:/DeSem/Projet/desenet-work/work/desenet-sensor/src/common/mdw/clockwork/ttime.cpp desenet-common/mdw/clockwork/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -DIDE_STM32CUBEIDE -DTC_STM32CUBEIDE -DUSE_DISPLAY -DDISPLAY_DRIVER_SSD1608 -c -I"E:/DeSem/Projet/desenet-work/work/desenet-sensor/ide-stm32cubeide/.." -I"E:/DeSem/Projet/desenet-work/work/desenet-sensor/ide-stm32cubeide/../src" -I"E:/DeSem/Projet/desenet-work/work/desenet-sensor/ide-stm32cubeide/platform/nucleo-stm32l476rg" -I"E:/DeSem/Projet/desenet-work/work/desenet-sensor/src/common/platform/nucleo-stm32l476rg" -I"E:/DeSem/Projet/desenet-work/work/desenet-sensor/src/common/platform/nucleo-stm32l476rg/mcu" -I"E:/DeSem/Projet/desenet-work/work/desenet-sensor/src/common/platform/nucleo-stm32l476rg/board" -I"E:/DeSem/Projet/desenet-work/work/desenet-sensor/src/common/platform/platform-common" -I"E:/DeSem/Projet/desenet-work/work/desenet-sensor/src/common/platform/platform-common/board" -I"E:/DeSem/Projet/desenet-work/work/desenet-sensor/src/common/platform" -I"E:/DeSem/Projet/desenet-work/work/desenet-sensor/src/common/mdw" -I"E:/DeSem/Projet/desenet-work/work/desenet-sensor/src/common/mdw/desenet" -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-desenet-2d-common-2f-mdw-2f-clockwork

clean-desenet-2d-common-2f-mdw-2f-clockwork:
	-$(RM) ./desenet-common/mdw/clockwork/clockwork.cyclo ./desenet-common/mdw/clockwork/clockwork.d ./desenet-common/mdw/clockwork/clockwork.o ./desenet-common/mdw/clockwork/clockwork.su ./desenet-common/mdw/clockwork/ttime.cyclo ./desenet-common/mdw/clockwork/ttime.d ./desenet-common/mdw/clockwork/ttime.o ./desenet-common/mdw/clockwork/ttime.su

.PHONY: clean-desenet-2d-common-2f-mdw-2f-clockwork

