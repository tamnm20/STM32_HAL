/*
 * stm32_gpio.c
 *
 *  Created on: Jan 22, 2024
 *      Author: TAMRD
 */


#include "stm32_gpio.h"

void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi)
{
	if(EnorDi == ENABLE){
//		if(pGPIOx == GPIOA ){
//			GPIOA_PCLK_EN();
//		}
		switch(pGPIOx){
			case GPIOA:
				GPIOA_PCLK_EN();
				break;
			case GPIOB:
				GPIOB_PCLK_EN();
				break;
			case GPIOB:
				GPIOB_PCLK_EN();
				break;
			case GPIOC:
				GPIOC_PCLK_EN();
				break;
			case GPIOD:
				GPIOD_PCLK_EN();
				break;
			case GPIOE:
				GPIOE_PCLK_EN();
				break;
			default:
				break;
		}
	}
	else{
		//
	}
}


void GPIO_Init(GPIO_Handle_t *pGPIOHandle){
	//enable the peripheral clock

	//1. Config mode

	//2. Config speed

	//3. Config pupd

	//.4 Config optype

	//5. Config Alt Functionality


}
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);
uint8_t GPIO_ReadPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
uint16_t GPIO_ReadPort(GPIO_RegDef_t *pGPIOx);
void GPIO_WritePin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value);
void GPIO_WritePort(GPIO_RegDef_t *pGPIOx, uint16_t Value);
void GPIO_TogglePin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);

void GPIO_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi);
void GPIO_IRQPriorityConfig(uint8_t IRQNumber, uint8_t IRQPriority);
void GPIO_IRQHandling(uint8_t PinNumber);
