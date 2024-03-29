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

void GPIO_Init(GPIO_Handle_t *pGPIOHandle)
{
  //enable the peripheral clock
  GPIO_PeriClockControl(pGPIOHandle ->pGPIOx, ENABLE);

  uint32_t currentmode = 0x0000UL, currentpin = 0x00, pinpos = 0x00, pos = 0x00;
  uint32_t tmpreg = 0x00, pinmask = 0x00;
/*---------------------------- GPIO Mode Configuration -----------------------*/
  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	//1. Config output type or input type
  currentmode = (uint32_t)pGPIOHandle->GPIO_pinConfig.GPIO_PinType;
  if (pGPIOHandle->GPIO_pinConfig.GPIO_PinMode != 0x00)
  {
	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	//2. Config mode and speed
    /* Output mode */
    currentmode |= pGPIOHandle->GPIO_pinConfig.GPIO_PinMode;
  }
/*---------------------------- GPIO CRL Configuration ------------------------*/
  /* Configure the eight low port pins */
  if (((uint32_t)pGPIOHandle-> GPIO_pinConfig.GPIO_PinNumber & ((uint32_t)0x00FF)) != 0x00)
  {
    tmpreg = pGPIOHandle -> pGPIOx -> CRL;
    while (((pGPIOHandle-> GPIO_pinConfig.GPIO_PinNumber) >> pinpos) != 0x00u)
    {
      pos = ((uint32_t)0x01) << pinpos;
      /* Get the port pins position */
      currentpin = (pGPIOHandle-> GPIO_pinConfig.GPIO_PinNumber) & pos;
      if (currentpin == pos)
      {
        pos = pinpos << 2;
        /* Clear the corresponding low control register bits */
        pinmask = ((uint32_t)0x0F) << pos;
        tmpreg &= ~pinmask;
        /* Write the mode configuration in the corresponding bits */
        tmpreg |= (currentmode << pos);
        																	//3. Config PUPD setting
        /* Reset the corresponding ODR bit */
        if (pGPIOHandle-> GPIO_pinConfig.GPIO_Pull == GPIO_PULLDOWN)
        {
          pGPIOHandle -> pGPIOx->BRR = (((uint32_t)0x01) << pinpos);
        }
        else
        {
          /* Set the corresponding ODR bit */
          if (pGPIOHandle-> GPIO_pinConfig.GPIO_Pull == GPIO_PULLUP)
          {
            pGPIOHandle -> pGPIOx->BSRR = (((uint32_t)0x01) << pinpos);
          }
        }
      }
	  pinpos++;
    }
    pGPIOHandle -> pGPIOx->CRL = tmpreg;
  }
/*---------------------------- GPIO CRH Configuration ------------------------*/
  /* Configure the eight high port pins */

  if (pGPIOHandle-> GPIO_pinConfig.GPIO_PinNumber > 0x00FF)
  {
	pinpos = 0;
    tmpreg = pGPIOHandle -> pGPIOx -> CRH;
    while (((pGPIOHandle-> GPIO_pinConfig.GPIO_PinNumber) >> pinpos) != 0x00u)
    {
      pos = (((uint32_t)0x01) << (pinpos + 0x08));
      /* Get the port pins position */
      currentpin = ((pGPIOHandle-> GPIO_pinConfig.GPIO_PinNumber) & pos);
      if (currentpin == pos)
      {
        pos = pinpos << 2;
        /* Clear the corresponding high control register bits */
        pinmask = ((uint32_t)0x0F) << pos;
        tmpreg &= ~pinmask;
        /* Write the mode configuration in the corresponding bits */
        tmpreg |= (currentmode << pos);
        /* Reset the corresponding ODR bit */
        if (pGPIOHandle-> GPIO_pinConfig.GPIO_Pull == GPIO_PULLDOWN)
        {
          pGPIOHandle -> pGPIOx->BRR = (((uint32_t)0x01) << (pinpos + 0x08));
        }
        /* Set the corresponding ODR bit */
        if (pGPIOHandle-> GPIO_pinConfig.GPIO_Pull == GPIO_PULLUP)
        {
          pGPIOHandle -> pGPIOx->BSRR = (((uint32_t)0x01) << (pinpos + 0x08));
        }
      }
	  pinpos++;
    }
    pGPIOHandle -> pGPIOx->CRH = tmpreg;
  }
}

//4. Config Alt Functionality
///**
//  * @brief  Selects the GPIO pin used as Event output.
//  * @param  GPIO_PortSource: selects the GPIO port to be used as source
//  *   for Event output.
//  *   This parameter can be GPIO_PortSourceGPIOx where x can be (A..E).
//  * @param  GPIO_PinSource: specifies the pin for the Event output.
//  *   This parameter can be GPIO_PinSourcex where x can be (0..15).
//  * @retval None
//  */
//void GPIO_EventOutputConfig(uint8_t GPIO_PortSource, uint8_t GPIO_PinSource)
//{
//  uint32_t tmpreg = 0x00;
//  /* Check the parameters */
//  assert_param(IS_GPIO_EVENTOUT_PORT_SOURCE(GPIO_PortSource));
//  assert_param(IS_GPIO_PIN_SOURCE(GPIO_PinSource));
//
//  tmpreg = AFIO->EVCR;
//  /* Clear the PORT[6:4] and PIN[3:0] bits */
//  tmpreg &= EVCR_PORTPINCONFIG_MASK;
//  tmpreg |= (uint32_t)GPIO_PortSource << 0x04;
//  tmpreg |= GPIO_PinSource;
//  AFIO->EVCR = tmpreg;
//}

void GPIO_DeInit(GPIO_RegDef_t *pGPIOx, uint32_t PinNumber){
  uint32_t currentpin = 0x00, pinpos = 0x00, pos = 0x00;
  uint32_t tmpreg = 0x00, pinmask = 0x00;
/*---------------------------- GPIO CRL Configuration ------------------------*/
  /* Configure the eight low port pins */
  if ((PinNumber & ((uint32_t)0x00FF)) != 0x00)
  {
	tmpreg = pGPIOx -> CRL;
	while ((PinNumber >> pinpos) != 0x00u)
	{
	  pos = ((uint32_t)0x01) << pinpos;
	  /* Get the port pins position */
	  currentpin = PinNumber & pos;
	  if (currentpin == pos)
	  {
		pos = pinpos << 2;
		/* Clear the corresponding low control register bits */
		pinmask = ((uint32_t)0x0F) << pos;
		tmpreg &= ~pinmask;
		/* Write Reset value 0x4 */
		tmpreg |= ((uint32_t)0x4) << pos;
		/* ODR default value is 0 */
		CLEAR_BIT(pGPIOx->ODR, currentpin);
	  }
	  pinpos++;
	}
	pGPIOx->CRL = tmpreg;
  }
/*---------------------------- GPIO CRH Configuration ------------------------*/
  /* Configure the eight high port pins */
  if (PinNumber > 0x00FF)
  {
	tmpreg = pGPIOx -> CRH;
	pinpos = 0x00;
	while ((PinNumber >> pinpos) != 0x00u)
	{
	  pos = (((uint32_t)0x01) << (pinpos + 0x08));
	  /* Get the port pins position */
	  currentpin = (PinNumber & pos);
	  if (currentpin == pos)
	  {
		pos = pinpos << 2;
		/* Clear the corresponding high control register bits */
		pinmask = ((uint32_t)0x0F) << pos;
		tmpreg &= ~pinmask;
		/* Write Reset value 0x4 */
		tmpreg |= ((uint32_t)0x4) << pos;
		/* ODR default value is 0 */
		CLEAR_BIT(pGPIOx->ODR, currentpin);
	  }
	  pinpos++;
	}
	pGPIOx->CRH = tmpreg;
  }
}


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

void GPIO_WritePin(GPIO_RegDef_t *pGPIOx, uint16_t PinNumber, uint8_t Value){
	if(Value){
		pGPIOx ->BSRR = PinNumber;
	}
	else{
		pGPIOx ->BRR = PinNumber;
	}
}
void GPIO_WritePort(GPIO_RegDef_t *pGPIOx, uint16_t Value){
	pGPIOx ->ODR = Value;
}
void GPIO_TogglePin(GPIO_RegDef_t *pGPIOx, uint16_t PinNumber){
	  uint32_t odr;
	  /* get current Output Data Register value */
	  odr = pGPIOx ->ODR;

	  /* Set selected pins that were at low level, and reset ones that were high */
	  pGPIOx ->BSRR = ((odr & PinNumber) << 16U) | (~odr & PinNumber);
}

void GPIO_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi);
void GPIO_IRQPriorityConfig(uint8_t IRQNumber, uint8_t IRQPriority);
void GPIO_IRQHandling(uint8_t PinNumber);
