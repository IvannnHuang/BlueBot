#include "3140_concur.h"
#include "led.h"
#include "process.h"
#include "analog.h"
#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "board.h"
#include "fsl_gpio.h"
#include "fsl_port.h"
#include "fsl_adc16.h"
#include "pin_mux.h"
#include "fsl_common.h"
#include "fsl_tpm.h"
#include "pwm.h"

const uint16_t jsx = 0;			// E-analog
const uint16_t jsy = 4;			// E-analog
const uint16_t vib = 31;		// E-digital
const uint16_t motor1 = 0;		// left motor
const uint16_t motor2 = 1;		// right motor

const uint16_t up = 1000;
const uint16_t down = 50;
const uint16_t bw1 = 40;
const uint16_t fw1 = 28;
const uint16_t bw2 = 28;
const uint16_t fw2 = 40;
uint16_t turndelay = 1000;
uint16_t vibration = 0;
uint16_t vibcount = 0;
uint16_t count = 0;


void red_flash_frdm(void) {
	for (int i = 0; i < 60; i++){
		red_toggle_frdm();
		delay(50);
	}
}

void BluBop_control (void)
{
    /* Init board hardware. */
    BOARD_InitPins();
    BOARD_BootClockRUN();
    BOARD_InitDebugConsole();

//    led_init();
    ADC_init();
    PWM_init();
	uint16_t x_pos, y_pos;
	SIM->SCGC5 |= SIM_SCGC5_PORTE_MASK;
	PORTE->PCR[vib] = PORT_PCR_MUX(1);
	PTE->PDDR &= ~(1 << vib);

	while(1) {
		vibration += (PTE->PDIR & (1 << vib)) >> vib;
		count += 1;
		x_pos = analogRead(jsx);
		y_pos = analogRead(jsy);
//		updateLCDWithDirection(x_pos, y_pos);
		PRINTF("x: %d , y: %d , vib: %d , count: %d \r\n", x_pos, y_pos, vibration, count);
		if (count == 20){
			count = 0;
			vibration = 0;
		}

		if (vibration > 10) {
			// Vibration detected, override joystick control
			set_PWM(0, 0);
			set_PWM(1, 0);
			PRINTF("Vibration detected! Overriding joystick.\r\n");
			red_flash_frdm();       // Flash red indicating vibration detection
			vibcount += 1;
			vibration = 0;
		}

		if (vibcount == 3) { 	// Perform square movement sequence
			for (int i = 0; i < 4; i++) {
				// Move forward
				set_PWM(motor1, fw1);
				set_PWM(motor2, fw2);
				delay(3000); // Adjust time per side of square

				// Turn left
				set_PWM(motor1, bw1);
				set_PWM(motor2, fw2);
				delay(turndelay); // Adjust time for 90 degree turn
			}
			// Stop after completing square
			set_PWM(motor1, 0);
			set_PWM(motor2, 0);
			vibcount = 0;
		}
		else {
			if (x_pos < up && x_pos > down && y_pos < up && y_pos > down) {
				// Center
				red_on_frdm();
				green_off_frdm();		// not moving
				set_PWM(motor1, 0);
				set_PWM(motor2, 0);
			} else if (y_pos >= up && x_pos < up && x_pos > down) {
				// Center left
				red_off_frdm();
				green_on_frdm();        // moving indication
				set_PWM(motor1, bw1);   // Motor1 slower backward
				set_PWM(motor2, fw2);
			} else if (y_pos <= down && x_pos < up && x_pos > down) {
				// Center right
				red_off_frdm();
				green_on_frdm();        // moving indication
				set_PWM(motor1, fw1);  // Motor1 faster backward
				set_PWM(motor2, bw2);
			} else if (x_pos <= down && y_pos < up && y_pos > down) {
				// Top center
				red_off_frdm();
				green_on_frdm();        // moving indication
				set_PWM(motor1, fw1);  // Motor1 backward
				set_PWM(motor2, fw2);
			} else if (x_pos <= down && y_pos <= down) {
				// Top left
				red_off_frdm();
				green_on_frdm();         // moving indication
				set_PWM(motor1, fw1);   // Motor1 forward
				set_PWM(motor2, 0);
			} else if (x_pos <= down && y_pos >= up) {
				// Top right
				red_off_frdm();
				green_on_frdm();         // moving indication
				set_PWM(motor1, 0);   // Motor1 forward
				set_PWM(motor2, fw2);
			}
			else if (x_pos >= up && y_pos < up && y_pos > down) {
				// Button center
				red_off_frdm();
				green_on_frdm();        // moving indication
				set_PWM(motor1, bw1);  // Motor1 backward
				set_PWM(motor2, bw2);
			} else if (x_pos >= up && y_pos >= up) {
				// Button left
				red_off_frdm();
				green_on_frdm();         // moving indication
				set_PWM(motor1, bw1);    // Motor1 slower forward
				set_PWM(motor2, 0);
			} else if (x_pos >= up && y_pos <= down) {
				// Button right
				red_off_frdm();
				green_on_frdm();         // moving indication
				set_PWM(motor1, 0);   // Motor1 faster forward
				set_PWM(motor2, bw2);
			}
		}
	}
}

int main(void) {

	// robot main function
	BluBop_control();

	return 0;
}
