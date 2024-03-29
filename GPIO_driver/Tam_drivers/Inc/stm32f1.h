/*
 * stm32f1.h
 *
 *  Created on: Jan 22, 2024
 *      Author: TAMRD
 */

#ifndef INC_STM32F1_H_
#define INC_STM32F1_H_

#include "stdint.h"
#define __vo volatile

//Buoc 1
#define FLASH_BASEADDR  0x08000000U
#define SRAM_BASEADDR   0x20000000U
#define ROM_BASEADDR	0x1FFFF000U

//Buoc 2
#define PERIPH_BASEADDR 	0x40000000U
#define APB1PERIPH_BASEADDR PERIPH_BASEADDR
#define APB2PERIPH_BASEADDR	0x40010000U
#define AHBPERIPH_BASEADDR	0x40018000U

//Buoc 3
#define EXTI_BASEADDR 	(APB2PERIPH_BASEADDR + 0x0400)
#define GPIOA_BASEADDR 	(APB2PERIPH_BASEADDR + 0x0800) //APB2
#define GPIOB_BASEADDR 	(APB2PERIPH_BASEADDR + 0x0C00)
#define GPIOC_BASEADDR 	(APB2PERIPH_BASEADDR + 0x1000)
#define GPIOD_BASEADDR 	(APB2PERIPH_BASEADDR + 0x1400)
#define GPIOE_BASEADDR 	(APB2PERIPH_BASEADDR + 0x1800)
#define USART1_BASEADDR (APB2PERIPH_BASEADDR + 0x3800)
#define SPI1_BASEADDR 	(APB2PERIPH_BASEADDR + 0x3000)

#define RCC_BASEADDR 	0x40021000U   //AHB

#define I2C1_BASEADDR 	(APB1PERIPH_BASEADDR + 0x5400) //APB1
#define I2C2_BASEADDR 	(APB1PERIPH_BASEADDR + 0x5800)
#define USART2_BASEADDR (APB1PERIPH_BASEADDR + 0x4800)
#define USART3_BASEADDR (APB1PERIPH_BASEADDR + 0x3800)
#define SPI2_BASEADDR 	(APB1PERIPH_BASEADDR + 0x3000)

//Buoc 4
typedef struct
{
	__vo uint32_t CRL;
	__vo uint32_t CRH;
	__vo uint32_t IDR;
	__vo uint32_t ODR;
	__vo uint32_t BSRR;
	__vo uint32_t BRR;
	__vo uint32_t LCKR;
}GPIO_RegDef_t;

// Buoc 5
#define GPIOA ((GPIO_RegDef_t*) GPIOA_BASEADDR)
#define GPIOB ((GPIO_RegDef_t*) GPIOB_BASEADDR)
#define GPIOC ((GPIO_RegDef_t*) GPIOC_BASEADDR)
#define GPIOD ((GPIO_RegDef_t*) GPIOD_BASEADDR)
#define GPIOE ((GPIO_RegDef_t*) GPIOE_BASEADDR)

typedef struct
{
  __vo uint32_t EVCR;
  __vo uint32_t MAPR;
  __vo uint32_t EXTICR[4];
  uint32_t RESERVED0;
  __vo uint32_t MAPR2;
} AFIO_RegDef_t;

typedef struct
{
	__vo uint32_t CR;
	__vo uint32_t CFGR;
	__vo uint32_t CIR;
	__vo uint32_t APB2RSTR;
	__vo uint32_t APB1RSTR;
	__vo uint32_t AHBENR;
	__vo uint32_t APB2ENR;
	__vo uint32_t APB1ENR;
	__vo uint32_t BDCR;
	__vo uint32_t CSR;
	__vo uint32_t AHBRSTR;
	__vo uint32_t CFGR2;
}RCC_RegDef_t;
#define RCC ((RCC_RegDef_t*) RCC_BASEADDR)

typedef struct
{
	__vo uint32_t IMR;
	__vo uint32_t EMR;
	__vo uint32_t RTSR;
	__vo uint32_t FTSR;
	__vo uint32_t SWIER;
	__vo uint32_t PR;

}EXTI_RegDef_t;
#define EXTI ((EXTI_RegDef_t*) EXTI_BASEADDR)

typedef struct
{
	__vo uint32_t CR1;
	__vo uint32_t CR2;
	__vo uint32_t SR;
	__vo uint32_t DR;
	__vo uint32_t CRCPR;
	__vo uint32_t RXCRCR;
	__vo uint32_t TXCRCR;
	__vo uint32_t I2SCFGR;
	__vo uint32_t I2SPR;

}SPI_RegDef_t;
#define SPI1 ((SPI_RegDef_t*) SPI1_BASEADDR)
#define SPI2 ((SPI_RegDef_t*) SPI2_BASEADDR)


typedef struct
{
	__vo uint32_t SR;
	__vo uint32_t DR;
	__vo uint32_t BRR;
	__vo uint32_t CR1;
	__vo uint32_t CR2;
	__vo uint32_t CR3;
	__vo uint32_t GTPR;

}USART_RegDef_t;
#define USART1 ((USART_RegDef_t*) USART1_BASEADDR)
#define USART2 ((USART_RegDef_t*) USART2_BASEADDR)
#define USART3 ((USART_RegDef_t*) USART3_BASEADDR)

typedef struct
{
	__vo uint32_t CR1;
	__vo uint32_t CR2;
	__vo uint32_t OAR1;
	__vo uint32_t OAR2;
	__vo uint32_t DR;
	__vo uint32_t SR1;
	__vo uint32_t SR2;
	__vo uint32_t CCR;
	__vo uint32_t TRISE;

}I2C_RegDef_t;
#define I2C1 ((I2C_RegDef_t*) I2C1_BASEADDR)
#define I2C2 ((I2C_RegDef_t*) I2C2_BASEADDR)

//buoc 6: Enable/Disable clock
//enable
#define GPIOA_PCLK_EN() (RCC->APB2ENR |= (1<<2))
#define GPIOB_PCLK_EN() (RCC->APB2ENR |= (1<<3))
#define GPIOC_PCLK_EN() (RCC->APB2ENR |= (1<<4))
#define GPIOD_PCLK_EN() (RCC->APB2ENR |= (1<<5))
#define GPIOE_PCLK_EN() (RCC->APB2ENR |= (1<<6))

#define I2C1_PCLK_EN() (RCC->APB1ENR |= (1<<21))
#define I2C2_PCLK_EN() (RCC->APB1ENR |= (1<<22))

#define SPI1_PCLK_EN() (RCC->APB2ENR |= (1<<12))
#define SPI2_PCLK_EN() (RCC->APB1ENR |= (1<<14))

#define USART1_PCLK_EN() (RCC->APB2ENR |= (1<<14))
#define USART2_PCLK_EN() (RCC->APB1ENR |= (1<<17))
#define USART3_PCLK_EN() (RCC->APB1ENR |= (1<<18))

//disable
#define GPIOA_PCLK_DI() (RCC->APB2ENR &=~(1<<2))
#define GPIOB_PCLK_DI() (RCC->APB2ENR &=~ (1<<3))
#define GPIOC_PCLK_DI() (RCC->APB2ENR &=~(1<<4))
#define GPIOD_PCLK_DI() (RCC->APB2ENR &=~(1<<5))
#define GPIOE_PCLK_DI() (RCC->APB2ENR &=~ (1<<6))

#define I2C1_PCLK_DI() (RCC->APB1ENR &=~(1<<21))
#define I2C2_PCLK_DI() (RCC->APB1ENR &=~ (1<<22))

#define SPI1_PCLK_DI() (RCC->APB2ENR &=~ (1<<12))
#define SPI2_PCLK_DI() (RCC->APB1ENR &=~ (1<<14))

#define USART1_PCLK_DI() (RCC->APB2ENR &=~ (1<<14))
#define USART2_PCLK_DI() (RCC->APB1ENR &=~ (1<<17))
#define USART3_PCLK_DI() (RCC->APB1ENR &=~ (1<<18))

#define ENABLE 1
#define DISABLE 0
#define SET ENABLE
#define RESET DISABLE
#define GPIO_PIN_SET SET
#define GPIO_PIN_RESET RESET
#define FLAG_RESET RESET
#define FLAG_SET SET

#define SET_BIT(REG, BIT)     ((REG) |= (BIT))
#define CLEAR_BIT(REG, BIT)   ((REG) &= ~(BIT))
#define READ_BIT(REG, BIT)    ((REG) & (BIT))
#define CLEAR_REG(REG)        ((REG) = (0x0))
#define WRITE_REG(REG, VAL)   ((REG) = (VAL))
#define READ_REG(REG)         ((REG))
#define MODIFY_REG(REG, CLEARMASK, SETMASK)  WRITE_REG((REG), (((READ_REG(REG)) & (~(CLEARMASK))) | (SETMASK)))
#define POSITION_VAL(VAL)     (__CLZ(__RBIT(VAL)))


#endif /* INC_STM32F1_H_ */
