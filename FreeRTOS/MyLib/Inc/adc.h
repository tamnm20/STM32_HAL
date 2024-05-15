/*
 * adc.h
 *
 *  Created on: May 11, 2024
 *      Author: TAMRD
 */

#ifndef INC_ADC_H_
#define INC_ADC_H_

#include "stm32f103xb.h"

void read_temp_init(void);
float adc_get_temp_ss(void);

#endif /* INC_ADC_H_ */
