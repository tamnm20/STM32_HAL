#ifndef UARTRINGBUFFER_H_
#define UARTRINGBUFFER_H_

#include "stm32f1xx_hal.h"

/* change the size of the buffer */
#define UART_BUFFER_SIZE 64

typedef struct
{
  unsigned char buffer[UART_BUFFER_SIZE];
  volatile unsigned int readIndex;
  volatile unsigned int writeIndex;
} ring_buffer;


/* Initialize the ring buffer */
void Ringbuf_init(void);

/* reads the data in the rx_buffer and increment the tail count in rx_buffer */
//int Uart_read(void);
char Uart_read(void);
/* writes the data to the tx_buffer and increment the head count in tx_buffer */
//void Uart_write(int c);
void Uart_write(uint8_t data);

/* function to send the string to the uart */
void Uart_sendstring(unsigned char *s);

//void Uart_sendApp (const char *s, uint8_t head);

/* Checks if the data is available to read in the rx_buffer */
int IsDataAvailable(void);
uint8_t IsFull(void);
uint8_t IsEmpty(void);

/* the ISR for the uart. put it in the IRQ handler */

#endif /* UARTRINGBUFFER_H_ */
