################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SDK/platform/drivers/src/flexio/flexio_common.c \
../SDK/platform/drivers/src/flexio/flexio_i2c_driver.c 

OBJS += \
./SDK/platform/drivers/src/flexio/flexio_common.o \
./SDK/platform/drivers/src/flexio/flexio_i2c_driver.o 

C_DEPS += \
./SDK/platform/drivers/src/flexio/flexio_common.d \
./SDK/platform/drivers/src/flexio/flexio_i2c_driver.d 


# Each subdirectory must supply rules for building sources it contributes
SDK/platform/drivers/src/flexio/%.o: ../SDK/platform/drivers/src/flexio/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@SDK/platform/drivers/src/flexio/flexio_common.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


