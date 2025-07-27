#ifndef ADC_H
#define ADC_H

// Function declarations
unsigned short readJoystickX(void);   // Reads the X-axis value from ADC0
unsigned short readJoystickY(void);   // Reads the Y-axis value from ADC1
void DelayFunction(void);             // Provides a simple delay
void initADC(void);                   // Initializes the ADC modules for the joystick

#endif /* ADC_H */
