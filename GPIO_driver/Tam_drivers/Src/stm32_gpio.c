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
		if(pGPIOx == GPIOA ){
			GPIOA_PCLK_EN();
		}
		else if(pGPIOx == GPIOB){
			GPIOB_PCLK_EN();
		}
		else if(pGPIOx == GPIOC){
			GPIOC_PCLK_EN();
		}
		else if(pGPIOx == GPIOD){
			GPIOD_PCLK_EN();
		}
		else if(pGPIOx == GPIOE){
			GPIOE_PCLK_EN();
		}
	}
	else{
		//
	}
}


void GPIO_Init(GPIO_Handle_t *pGPIOHandle){
	//enable the peripheral clock
	GPIO_PeriClockControl(pGPIOHandle ->pGPIOx, ENABLE);
	uint32_t temp =0; //temp. register

		if(pGPIOHandle-> GPIO_pinConfig.GPIO_PinNumber < 8){ //pin 0 - 7 CRL
			//1. Config mode and speed
			pGPIOHandle -> pGPIOx -> CRL &= ~(0xF << (4* pGPIOHandle-> GPIO_pinConfig.GPIO_PinNumber)); //clear bit
			temp = (pGPIOHandle->GPIO_pinConfig.GPIO_PinMode << (4* pGPIOHandle-> GPIO_pinConfig.GPIO_PinNumber));
			//2. Config output type or input type
			temp |= (pGPIOHandle->GPIO_pinConfig.GPIO_PinType << ((4* pGPIOHandle-> GPIO_pinConfig.GPIO_PinNumber)+2));
			pGPIOHandle -> pGPIOx -> CRL |= temp;
		}
		else{ //pin 8 - 15 CRH
			//1. Config mode and speed
			pGPIOHandle -> pGPIOx -> CRH &= ~(0xF << (4* (pGPIOHandle-> GPIO_pinConfig.GPIO_PinNumber - 8))); //clear bit
			temp = (pGPIOHandle->GPIO_pinConfig.GPIO_PinMode << (4* pGPIOHandle-> GPIO_pinConfig.GPIO_PinNumber- 8));
			//2. Config output type or input type
			temp |= (pGPIOHandle->GPIO_pinConfig.GPIO_PinType << ((4* pGPIOHandle-> GPIO_pinConfig.GPIO_PinNumber - 8)+2));
			//pGPIOHandle -> pGPIOx -> CRH |= temp;
			pGPIOHandle -> pGPIOx -> CRH |= 0x00200000UL;
		}

	//4. Config PUPD setting

        if (pGPIOHandle-> GPIO_pinConfig.GPIO_Pull == GPIO_NOPULL)
        {
        	//
        }
        else if (pGPIOHandle-> GPIO_pinConfig.GPIO_Pull == GPIO_PULLUP)
        {
          /* Set the corresponding ODR bit */
        	pGPIOHandle -> pGPIOx ->BSRR |= 1 << (pGPIOHandle-> GPIO_pinConfig.GPIO_PinNumber);
        }
        else /* GPIO_PULLDOWN */
        {
          /* Reset the corresponding ODR bit */
          pGPIOHandle -> pGPIOx ->BRR |= 1 << (pGPIOHandle-> GPIO_pinConfig.GPIO_PinNumber);
        }

	//3. Config Alt Functionality
//        if(pGPIOHandle->GPIO_pinConfig.GPIO_PinType >1 ){
//
//        }

}
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);
uint8_t GPIO_ReadPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber){
	uint8_t value;
	value = (uint8_t) (pGPIOx -> IDR >> PinNumber) & 0x00000001;
	return value;
}
uint16_t GPIO_ReadPort(GPIO_RegDef_t *pGPIOx){
	uint16_t value;
	value = (uint16_t)(pGPIOx -> IDR);
	return value;
}

void GPIO_WritePin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value){
	if(Value){
		pGPIOx ->ODR |= (1 << PinNumber);
	}
	else{
		pGPIOx ->ODR &= ~(1 << PinNumber);
	}
}
void GPIO_WritePort(GPIO_RegDef_t *pGPIOx, uint16_t Value){
	pGPIOx ->ODR = Value;
}
void GPIO_TogglePin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber){
	pGPIOx ->ODR ^= (1 << PinNumber);
}

void GPIO_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi);
void GPIO_IRQPriorityConfig(uint8_t IRQNumber, uint8_t IRQPriority);
void GPIO_IRQHandling(uint8_t PinNumber);