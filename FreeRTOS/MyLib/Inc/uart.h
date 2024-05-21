/*
 * uart.h
 *
 *  Created on: May 11, 2024
 *      Author: TAMRD
 */

#ifndef INC_UART_H_
#define INC_UART_H_

#include "stm32f103xb.h"
#include <stdio.h>
#include "string.h"
#include <stdarg.h>

#define GPIOA_BASE_ARR 0x40010800
#define AFIO_BASE_ARR 0x40010000
#define USART1_BASE_ARR 0x40013800
#define DMA1_BASE_ARR 0x40020000

void UART1_init(void);

void UART2_init(void);

void uart_printf(char* format, ...);

void USART1_IRQHandler(void);

void USART2_IRQHandler(void);

void UART1_Send_1byte (char data);

#endif /* INC_UART_H_ */
