################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/Final\ Project.c \
../source/Serial.c \
../source/analog.c \
../source/led.c \
../source/mtb.c \
../source/pwm.c \
../source/semihost_hardfault.c 

S_SRCS += \
../source/led_lowlevel.s 

C_DEPS += \
./source/Final\ Project.d \
./source/Serial.d \
./source/analog.d \
./source/led.d \
./source/mtb.d \
./source/pwm.d \
./source/semihost_hardfault.d 

OBJS += \
./source/Final\ Project.o \
./source/Serial.o \
./source/analog.o \
./source/led.o \
./source/led_lowlevel.o \
./source/mtb.o \
./source/pwm.o \
./source/semihost_hardfault.o 


# Each subdirectory must supply rules for building sources it contributes
source/Final\ Project.o: ../source/Final\ Project.c source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -DCPU_MKL46Z256VLL4_cm0plus -DCPU_MKL46Z256VLL4 -DFRDM_KL46Z -DFREEDOM -DPRINTF_FLOAT_ENABLE=0 -DSCANF_FLOAT_ENABLE=0 -DPRINTF_ADVANCED_ENABLE=0 -DSCANF_ADVANCED_ENABLE=0 -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -D__REDLIB__ -I"C:\Users\qijin\Documents\College Works\2024 Spring\Ece3140\Final Project\frdmkl46z_hello_world\source" -I"C:\Users\qijin\Documents\College Works\2024 Spring\Ece3140\Final Project\frdmkl46z_hello_world" -I"C:\Users\qijin\Documents\College Works\2024 Spring\Ece3140\Final Project\frdmkl46z_hello_world\CMSIS" -I"C:\Users\qijin\Documents\College Works\2024 Spring\Ece3140\Final Project\frdmkl46z_hello_world\drivers" -I"C:\Users\qijin\Documents\College Works\2024 Spring\Ece3140\Final Project\frdmkl46z_hello_world\startup" -I"C:\Users\qijin\Documents\College Works\2024 Spring\Ece3140\Final Project\frdmkl46z_hello_world\utilities" -I"C:\Users\qijin\Documents\College Works\2024 Spring\Ece3140\Final Project\frdmkl46z_hello_world\board\src" -I"C:\Users\qijin\Documents\College Works\2024 Spring\Ece3140\Final Project\frdmkl46z_hello_world\board" -O0 -fno-common -g -gdwarf-4 -Wall -c  -ffunction-sections  -fdata-sections  -ffreestanding  -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"source/Final Project.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

source/%.o: ../source/%.c source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -DCPU_MKL46Z256VLL4_cm0plus -DCPU_MKL46Z256VLL4 -DFRDM_KL46Z -DFREEDOM -DPRINTF_FLOAT_ENABLE=0 -DSCANF_FLOAT_ENABLE=0 -DPRINTF_ADVANCED_ENABLE=0 -DSCANF_ADVANCED_ENABLE=0 -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -D__REDLIB__ -I"C:\Users\qijin\Documents\College Works\2024 Spring\Ece3140\Final Project\frdmkl46z_hello_world\source" -I"C:\Users\qijin\Documents\College Works\2024 Spring\Ece3140\Final Project\frdmkl46z_hello_world" -I"C:\Users\qijin\Documents\College Works\2024 Spring\Ece3140\Final Project\frdmkl46z_hello_world\CMSIS" -I"C:\Users\qijin\Documents\College Works\2024 Spring\Ece3140\Final Project\frdmkl46z_hello_world\drivers" -I"C:\Users\qijin\Documents\College Works\2024 Spring\Ece3140\Final Project\frdmkl46z_hello_world\startup" -I"C:\Users\qijin\Documents\College Works\2024 Spring\Ece3140\Final Project\frdmkl46z_hello_world\utilities" -I"C:\Users\qijin\Documents\College Works\2024 Spring\Ece3140\Final Project\frdmkl46z_hello_world\board\src" -I"C:\Users\qijin\Documents\College Works\2024 Spring\Ece3140\Final Project\frdmkl46z_hello_world\board" -O0 -fno-common -g -gdwarf-4 -Wall -c  -ffunction-sections  -fdata-sections  -ffreestanding  -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

source/%.o: ../source/%.s source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU Assembler'
	arm-none-eabi-gcc -c -x assembler-with-cpp -D__REDLIB__ -I"C:\Users\qijin\Documents\College Works\2024 Spring\Ece3140\Final Project\frdmkl46z_hello_world\source" -I"C:\Users\qijin\Documents\College Works\2024 Spring\Ece3140\Final Project\frdmkl46z_hello_world" -I"C:\Users\qijin\Documents\College Works\2024 Spring\Ece3140\Final Project\frdmkl46z_hello_world\CMSIS" -I"C:\Users\qijin\Documents\College Works\2024 Spring\Ece3140\Final Project\frdmkl46z_hello_world\drivers" -I"C:\Users\qijin\Documents\College Works\2024 Spring\Ece3140\Final Project\frdmkl46z_hello_world\startup" -I"C:\Users\qijin\Documents\College Works\2024 Spring\Ece3140\Final Project\frdmkl46z_hello_world\utilities" -I"C:\Users\qijin\Documents\College Works\2024 Spring\Ece3140\Final Project\frdmkl46z_hello_world\board\src" -I"C:\Users\qijin\Documents\College Works\2024 Spring\Ece3140\Final Project\frdmkl46z_hello_world\board" -g3 -gdwarf-4 -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -specs=redlib.specs -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-source

clean-source:
	-$(RM) ./source/Final\ Project.d ./source/Final\ Project.o ./source/Serial.d ./source/Serial.o ./source/analog.d ./source/analog.o ./source/led.d ./source/led.o ./source/led_lowlevel.o ./source/mtb.d ./source/mtb.o ./source/pwm.d ./source/pwm.o ./source/semihost_hardfault.d ./source/semihost_hardfault.o

.PHONY: clean-source

