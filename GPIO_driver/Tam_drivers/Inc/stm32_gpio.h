/*
 * stm32_gpio.h
 *
 *  Created on: Jan 22, 2024
 *      Author: TAMRD
 */

#ifndef INC_STM32_GPIO_H_
#define INC_STM32_GPIO_H_

#include "stm32f1.h"

typedef struct
{
	uint16_t GPIO_PinNumber;
	uint8_t GPIO_PinMode;
	uint8_t GPIO_PinType;
	uint8_t GPIO_Pull;
}GPIO_PinConfig_t;

typedef struct
{
	GPIO_RegDef_t *pGPIOx;
	GPIO_PinConfig_t GPIO_pinConfig;
}GPIO_Handle_t;

#define GPIO_PIN_0                 ((uint16_t)0x0001)  /* Pin 0 selected    */
#define GPIO_PIN_1                 ((uint16_t)0x0002)  /* Pin 1 selected    */
#define GPIO_PIN_2                 ((uint16_t)0x0004)  /* Pin 2 selected    */
#define GPIO_PIN_3                 ((uint16_t)0x0008)  /* Pin 3 selected    */
#define GPIO_PIN_4                 ((uint16_t)0x0010)  /* Pin 4 selected    */
#define GPIO_PIN_5                 ((uint16_t)0x0020)  /* Pin 5 selected    */
#define GPIO_PIN_6                 ((uint16_t)0x0040)  /* Pin 6 selected    */
#define GPIO_PIN_7                 ((uint16_t)0x0080)  /* Pin 7 selected    */
#define GPIO_PIN_8                 ((uint16_t)0x0100)  /* Pin 8 selected    */
#define GPIO_PIN_9                 ((uint16_t)0x0200)  /* Pin 9 selected    */
#define GPIO_PIN_10                ((uint16_t)0x0400)  /* Pin 10 selected   */
#define GPIO_PIN_11                ((uint16_t)0x0800)  /* Pin 11 selected   */
#define GPIO_PIN_12                ((uint16_t)0x1000)  /* Pin 12 selected   */
#define GPIO_PIN_13                ((uint16_t)0x2000)  /* Pin 13 selected   */
#define GPIO_PIN_14                ((uint16_t)0x4000)  /* Pin 14 selected   */
#define GPIO_PIN_15                ((uint16_t)0x8000)  /* Pin 15 selected   */
#define GPIO_PIN_All               ((uint16_t)0xFFFF)  /* All pins selected */

//Mode, speed

#define GPIO_MODE_IN		0	//00: Input mode (reset state)
#define GPIO_MODE_OUT_10M	1	//01: Output mode, max speed 10 MHz.
#define GPIO_MODE_OUT_2M	2	//10: Output mode, max speed 2 MHz.
#define GPIO_MODE_OUT_50M	3	//11: Output mode, max speed 50 MHz

//Type
//In input mode (MODE[1:0]=00):
#define GPIO_MODE_ANALOG	0	//00: Analog mode
#define GPIO_IN_FLOATING	1	//01: Floating input (reset state)
#define GPIO_IN_PU_PD		2	//10: Input with pull-up / pull-down
								//11: Reserved
//In output mode (MODE[1:0] >00):
#define GPIO_MODE_OUTPUT_PP		0	//00: General purpose output push-pull
#define GPIO_MODE_OUTPUT_OD 	1	//01: General purpose output Open-drain
#define GPIO_MODE_AF_PP			2	//10: Alternate function output Push-pull
#define GPIO_MODE_AF_OD			3	//11: Alternate function output Open-drain

// Pull-Up Pull-Down
/** @defgroup GPIO_pull_define GPIO pull define
  * @brief GPIO Pull-Up or Pull-Down Activation
  * @{
  */
#define  GPIO_NOPULL        0x00000000u   /*!< No Pull-up or Pull-down activation  */
#define  GPIO_PULLUP        0x00000001u   /*!< Pull-up activation                  */
#define  GPIO_PULLDOWN      0x00000002u   /*!< Pull-down activation                */

void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi);
void GPIO_Init(GPIO_Handle_t *pGPIOHandle);
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx, uint32_t PinNumber);
uint8_t GPIO_ReadPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
uint16_t GPIO_ReadPort(GPIO_RegDef_t *pGPIOx);
void GPIO_WritePin(GPIO_RegDef_t *pGPIOx, uint16_t PinNumber, uint8_t Value);
void GPIO_WritePort(GPIO_RegDef_t *pGPIOx, uint16_t Value);
void GPIO_TogglePin(GPIO_RegDef_t *pGPIOx, uint16_t PinNumber);

void GPIO_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi);
void GPIO_IRQPriorityConfig(uint8_t IRQNumber, uint8_t IRQPriority);
void GPIO_IRQHandling(uint8_t PinNumber);






#endif /* INC_STM32_GPIO_H_ */
