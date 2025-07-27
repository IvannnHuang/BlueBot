#include "analog.h"
#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "board.h"
#include "fsl_gpio.h"
#include "fsl_port.h"
#include "fsl_adc16.h"
#include "pin_mux.h"



// Initialize ADC for a specific channel
void ADC_init(void) {
	adc16_config_t cfg;

	ADC16_GetDefaultConfig(&cfg);
	cfg.resolution = kADC16_ResolutionSE10Bit;
	cfg.clockSource = kADC16_ClockSourceAsynchronousClock;
	cfg.enableAsynchronousClock = true;

	ADC16_Init(ADC0, &cfg);
	ADC16_EnableHardwareTrigger(ADC0, false);
	ADC16_DoAutoCalibration(ADC0);
}

// Read ADC value from a specific channel
uint16_t analogRead(uint32_t channel) {
	adc16_channel_config_t chCfg;

	chCfg.channelNumber = channel;
	chCfg.enableInterruptOnConversionCompleted = false;
	chCfg.enableDifferentialConversion = false;

	ADC16_SetChannelConfig(ADC0, 0, &chCfg);
	while (!(ADC16_GetChannelStatusFlags(ADC0, 0) & kADC16_ChannelConversionDoneFlag)) {
	}
	return ADC16_GetChannelConversionValue(ADC0, 0);
}



