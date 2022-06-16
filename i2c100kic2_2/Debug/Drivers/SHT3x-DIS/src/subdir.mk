################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/SHT3x-DIS/src/sht3x_dis.c \
../Drivers/SHT3x-DIS/src/sht3x_dis_stm32F4xx_port.c 

OBJS += \
./Drivers/SHT3x-DIS/src/sht3x_dis.o \
./Drivers/SHT3x-DIS/src/sht3x_dis_stm32F4xx_port.o 

C_DEPS += \
./Drivers/SHT3x-DIS/src/sht3x_dis.d \
./Drivers/SHT3x-DIS/src/sht3x_dis_stm32F4xx_port.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/SHT3x-DIS/src/%.o Drivers/SHT3x-DIS/src/%.su: ../Drivers/SHT3x-DIS/src/%.c Drivers/SHT3x-DIS/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Gabriel/Documents/GitHub/PCSE/i2c100kic2_2/Drivers/SHT3x-DIS" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-SHT3x-2d-DIS-2f-src

clean-Drivers-2f-SHT3x-2d-DIS-2f-src:
	-$(RM) ./Drivers/SHT3x-DIS/src/sht3x_dis.d ./Drivers/SHT3x-DIS/src/sht3x_dis.o ./Drivers/SHT3x-DIS/src/sht3x_dis.su ./Drivers/SHT3x-DIS/src/sht3x_dis_stm32F4xx_port.d ./Drivers/SHT3x-DIS/src/sht3x_dis_stm32F4xx_port.o ./Drivers/SHT3x-DIS/src/sht3x_dis_stm32F4xx_port.su

.PHONY: clean-Drivers-2f-SHT3x-2d-DIS-2f-src

