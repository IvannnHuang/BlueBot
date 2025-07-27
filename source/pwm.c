#include "pwm.h"
#include "fsl_debug_console.h"
#include "board.h"
#include "fsl_common.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "fsl_port.h"


void PWM_init(void) {
	// Enable clock for TPM1
	SIM->SCGC6 |= SIM_SCGC6_TPM1_MASK;
	SIM->SCGC5 |= SIM_SCGC5_PORTB_MASK;

	// Configure clock source for TPM
	SIM->SOPT2 |= SIM_SOPT2_TPMSRC(1);
	TPM1 -> STATUS = 0;	//	clear status

	// Configure PORTA12 and PORTA13 for TPM1_CH0 and TPM1_CH1
	PORTB->PCR[0] = PORT_PCR_MUX(3);  // TPM1_CH0
	PORTB->PCR[1] = PORT_PCR_MUX(3);  // TPM1_CH1

	// Set TPM1 to up-counting mode
	TPM1->SC = TPM_SC_PS(3) | TPM_SC_CMOD(1); // Prescaler = 8, up-counting mode

	// Set period for a 50 Hz PWM signal (20 ms period)
	TPM1->MOD = DEFAULT_SYSTEM_CLOCK / 25;

	// Configure TPM1_CH0 and TPM1_CH1
	TPM1->CONTROLS[0].CnSC = TPM_CnSC_MSB_MASK | TPM_CnSC_ELSA_MASK;
	TPM1->CONTROLS[1].CnSC = TPM_CnSC_MSB_MASK | TPM_CnSC_ELSA_MASK;
}

void set_PWM(uint16_t channel, uint16_t dutyCycle){
	if (dutyCycle > 100) {
		dutyCycle = 100;
	}
	TPM1 -> CONTROLS[channel].CnV = TPM1 -> MOD / 40 * (dutyCycle);
	for (int i = 0; i < 25000; i++) {};
}

uint16_t map(uint16_t x, uint16_t in_min, uint16_t in_max, uint16_t out_min, uint16_t out_max) {
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

