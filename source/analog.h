#define __ANALOG_H__

#include <stdlib.h>
#include <MKL46Z4.h>

void ADC_init(void);
uint16_t analogRead(uint32_t channel);
void PWM_init(void);
void TPM_UpdateDutyCycle(uint16_t channel, uint32_t dutyCycle);
uint16_t map(uint16_t x, uint16_t in_min, uint16_t in_max, uint16_t out_min, uint16_t out_max);
