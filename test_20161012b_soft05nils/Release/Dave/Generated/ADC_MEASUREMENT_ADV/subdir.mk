################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Dave/Generated/ADC_MEASUREMENT_ADV/adc_measurement_adv.c \
../Dave/Generated/ADC_MEASUREMENT_ADV/adc_measurement_adv_conf.c 

OBJS += \
./Dave/Generated/ADC_MEASUREMENT_ADV/adc_measurement_adv.o \
./Dave/Generated/ADC_MEASUREMENT_ADV/adc_measurement_adv_conf.o 

C_DEPS += \
./Dave/Generated/ADC_MEASUREMENT_ADV/adc_measurement_adv.d \
./Dave/Generated/ADC_MEASUREMENT_ADV/adc_measurement_adv_conf.d 


# Each subdirectory must supply rules for building sources it contributes
Dave/Generated/ADC_MEASUREMENT_ADV/%.o: ../Dave/Generated/ADC_MEASUREMENT_ADV/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM-GCC C Compiler'
	"$(TOOLCHAIN_ROOT)/bin/arm-none-eabi-gcc" -MMD -MT "$@" -DXMC1302_Q024x0064 -I"$(PROJECT_LOC)/Libraries/XMCLib/inc" -I"$(PROJECT_LOC)/Libraries/CMSIS/Include" -I"$(PROJECT_LOC)/Libraries/CMSIS/Infineon/XMC1300_series/Include" -I"$(PROJECT_LOC)" -I"$(PROJECT_LOC)/Dave/Generated" -I"$(PROJECT_LOC)/Libraries" -Os -ffunction-sections -fdata-sections -Wall -std=gnu99 -Wa,-adhlns="$@.lst" -pipe -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d) $@" -mcpu=cortex-m0 -mthumb -o "$@" "$<" 
	@echo 'Finished building: $<'
	@echo.
