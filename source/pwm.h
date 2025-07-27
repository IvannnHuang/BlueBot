#include "MKL46Z4.h"
#include "fsl_clock.h"
#include "fsl_port.h"
#include "fsl_tpm.h"

void PWM_init(void);
void set_PWM(uint16_t channel, uint16_t dutyCycle);
