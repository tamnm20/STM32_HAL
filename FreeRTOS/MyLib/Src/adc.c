/*
 * adc.c
 *
 *  Created on: May 11, 2024
 *      Author: TAMRD
 */

#include "adc.h"

void read_temp_init(void)
{
	RCC ->CFGR &= ~(0b11<<14);
	RCC ->CFGR |= (0b10<<14);

    RCC-> APB2ENR |= RCC_APB2ENR_ADC1EN;

    ADC1-> SMPR1 |= (0b111<<18); //sample time: 239.5 cycles
    ADC1-> JSQR &= ~(0b11<<20); //00: 1 conversion
    ADC1-> JSQR |= (16<<15); //set source for JSQ4 is temp sensor (CH16)

    ADC1-> CR2 |= (1<<23); //enable temp sensor

    ADC1-> CR2 |= (1<<0); //Enable ADC and to start conversion
}

float adc_get_temp_ss(void)
{
    float temp = 0;
    float vin = 0;
    uint16_t raw_data = 0;

	ADC1->CR2 |= (0b111 << 12) ;//External event select for injected group: JSWSTART
	ADC1->CR2 |= (0b1 << 15) ;//1: Conversion on external event enabled

    // trigger ADC start convert
    ADC1-> CR2 |= (1u<<21);//Start conversion of injected channels

    //wait until end of conversion
    while(((ADC1-> SR>>2)&1) == 0);
    ADC1-> SR &= ~(1u<<2); //clear JEOC flag

    raw_data = ADC1-> JDR1; //read ADC data form JDR1 (data of JSQ4)

    vin = (raw_data*3300.0)/4095.0;

    temp = ((1430.0 - vin) / 4.3) + 25.0;

    return temp;
}
