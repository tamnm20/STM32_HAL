/*
 * uart.c
 *
 *  Created on: May 11, 2024
 *      Author: TAMRD
 */

#include "uart.h"
//char recv_data[32];
//int rx_index = 0;

void UART1_init()
{
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
	//register (0x4001 0000)AFIO_MAPR: UART1 default on PA9, PA10  neu muon dung PB6, PB7 set USART1_REMAP len 1
	uint32_t * AFIO_MAPR = (uint32_t *) (AFIO_BASE_ARR + 0x04);
	* AFIO_MAPR &= ~(1<<2);
	//set PA9 as UART1_TX, PA10 as UART1_RX
	uint32_t * GPIOA_CRH = (uint32_t *) (GPIOA_BASE_ARR + 0x04);
	*GPIOA_CRH &= ~ (0xff << 4);// clear MODE, CNF for PA9, PA10
	*GPIOA_CRH |= (0b10<<4)|(0b10<<6); //PA9 output 2MHz, Alternate function output Push-pull

	*GPIOA_CRH |= (0b01<<10); 		//set PA10 Floating input

/*
 * UART
 * 	+baudrate: 9600
 * 	+ frame:
 * 		data len: 8 bits
 * 		parity (none/odd/even): none
 */
	RCC->APB2ENR |= RCC_APB2ENR_USART1EN; //72Mhz set in clock.c USART1 in APB2 --> f_clock = 72Mhz
	uint32_t * USART_BRR = (uint32_t *) (USART1_BASE_ARR + 0x08);
	//* USART_BRR = (468 << 4) | (12 << 0); //baudrate 9600
	* USART_BRR = (39 << 4) | (1 << 0); //baudrate 115200
	uint32_t * USART_CR1 = (uint32_t *) (USART1_BASE_ARR + 0x0C);
	* USART_CR1 &= ~(1<<10); //disable parity control = parity: none
	//* USART_CR1 &= ~(1<<12); //1 Start bit, 8 Data bits, n Stop bit
	* USART_CR1 &= ~(1<<12); //1 Start bit, 8 Data bits, n Stop bit
	* USART_CR1 |= (1<<13)|(1<<3)|(1<<2); //enable UART, TX, RX

//#if 1
//	//RXNE interrupt enable -> when RXNE is set, UART1 generate interrupt event send to NVIC
//	*USART_CR1 |= (1<<5);
//	//NVIC accept interrupt event, which is send from UART1
//	NVIC->ISER1 |= (1<<5);
//#else
//	//when RXNE is set, send signal to DMA1, DMA1 move data to RAM
//	uint32_t * USART_CR3 = (uint32_t *) (USART1_BASE_ARR + 0x14);
//	*USART_CR3 |= (1<<6); //DMA mode is enabled for reception
//#endif
}

void UART2_init()
{
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
	//register (0x4001 0000)AFIO_MAPR: UART2 default on TX/PA2, RX/PA3  neu muon dung TX/PD5, RX/PD6 set USART2_REMAP len 1
//	uint32_t * AFIO_MAPR = (uint32_t *) (AFIO_BASE_ARR + 0x04);
//	* AFIO_MAPR &= ~(1<<3);
	AFIO->MAPR &= ~(1<<3);
	//set PA2 as UART2_TX, PA3 as UART2_RX
	//uint32_t * GPIOA_CRH = (uint32_t *) (GPIOA_BASE_ARR + 0x04);
	//*GPIOA_CRH &= ~ (0xff << 4);// clear MODE, CNF for PA9, PA10
	GPIOA->CRL &= ~(0xff<<8);// clear MODE, CNF for PA2, PA3
	//*GPIOA_CRH |= (0b10<<4)|(0b10<<6); //PA9 output 2MHz, Alternate function output Push-pull
	GPIOA->CRL |= (0b11<<8)|(0b10<<10); //PA2 output 50MHz, Alternate function output Push-pull
	//*GPIOA_CRH |= (0b01<<10); 		//set PA10 Floating input
	GPIOA->CRL |= (0b01<<14); //set PA3 Floating input

/*
 * UART
 * 	+baudrate: 115200
 * 	+ frame:
 * 		data len: 8 bits
 * 		parity (none/odd/even): none
 */
	RCC->APB1ENR |= RCC_APB1ENR_USART2EN; //32Mhz set in clock.c USART1 in APB2 --> f_clock = 36Mhz
	//uint32_t * USART_BRR = (uint32_t *) (USART1_BASE_ARR + 0x08);
	//* USART_BRR = (468 << 4) | (12 << 0); //baudrate 9600
	//* USART_BRR = (39 << 4) | (1 << 0); //baudrate 115200
	USART2->BRR = (19 << 4) | (8 << 0);//baudrate 115200
	//uint32_t * USART_CR1 = (uint32_t *) (USART1_BASE_ARR + 0x0C);
	//* USART_CR1 &= ~(1<<10); //disable parity control = parity: none
	USART2->CR1 &= ~(1<<10); //disable parity control = parity: none
	//* USART_CR1 &= ~(1<<12); //1 Start bit, 8 Data bits, n Stop bit
	USART2->CR1 &= ~(1<<12); //1 Start bit, 8 Data bits, n Stop bit
	//* USART_CR1 |= (1<<13)|(1<<3)|(1<<2); //enable UART, TX, RX
	USART2->CR1 |= (1<<13)|(1<<3)|(1<<2); //enable UART, TX, RX

#if 1
	//RXNE interrupt enable -> when RXNE is set, UART2 generate interrupt event send to NVIC
	USART2->CR1 |= (1<<5);
	//NVIC accept interrupt event, which is send from UART2
	//uint32_t *ISER1 = (uint32_t *) (0xE000E104);
	//*ISER1 |= (1<<(38-32));
	NVIC->ISER[1] |= (1<<6);
#else
	//when RXNE is set, send signal to DMA1, DMA1 move data to RAM
	uint32_t * USART_CR3 = (uint32_t *) (USART1_BASE_ARR + 0x14);
	*USART_CR3 |= (1<<6); //DMA mode is enabled for reception
#endif
}

void UART1_Send_1byte (char data)
{
	uint32_t *USART_SR = (uint32_t *) (USART1_BASE_ARR + 0x00);
	uint32_t *USART_DR = (uint32_t *) (USART1_BASE_ARR + 0x04);
	while(((*USART_SR >> 7) & 1) == 0);	//Wait Transmit data register empty
	*USART_DR = data;					// Write data to DR to UART transfer data via Tx (PA9)
	while(((*USART_SR >> 6) & 1) == 0);	//Wait Transmission complete
	*USART_SR &= ~(1<<6); 				//clear TC flag
}

static void UART1_Send_String (char * msg)
{
	int msg_len = strlen(msg);
	for(int i=0;i<msg_len;i++)
	{
		UART1_Send_1byte(msg[i]);
	}
}

void uart_printf(char* format, ...)
{
	va_list aptr;
	va_start(aptr, format);
	char buffer[128] = {0};
	vsprintf(buffer, format, aptr);
	UART1_Send_String(buffer);
	va_end(aptr);
}

void USART1_IRQHandler(void)
{
//	uint32_t *USART_DR = (uint32_t *) (USART1_BASE_ARR + 0x04);
//	recv_data[rx_index++]= *USART_DR;
//	if(strstr(recv_data, "LED ON") != NULL)
//	{
//		led_control(1);
//		rx_index = 0;
//		memset(recv_data, 0, sizeof(recv_data));
//	}
//	else if (strstr(recv_data, "LED OFF") != NULL)
//	{
//		led_control(0);
//		rx_index = 0;
//		memset(recv_data, 0, sizeof(recv_data));
//	}
}

void USART2_IRQHandler(void)
{
//	uint32_t *USART_DR = (uint32_t *) (USART1_BASE_ARR + 0x04);
//	recv_data[rx_index++]= *USART_DR;
//	if(strstr(recv_data, "LED ON") != NULL)
//	{
//		led_control(1);
//		rx_index = 0;
//		memset(recv_data, 0, sizeof(recv_data));
//	}
//	else if (strstr(recv_data, "LED OFF") != NULL)
//	{
//		led_control(0);
//		rx_index = 0;
//		memset(recv_data, 0, sizeof(recv_data));
//	}
}
