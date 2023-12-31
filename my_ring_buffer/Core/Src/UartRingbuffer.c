/*
 * UartRingbuffer.c
 *
 *  Created on: 10-Jul-2019
 *      Author: Controllerstech
 *
 *  Modified on: 11-April-2020
 */

#include "UartRingbuffer.h"
#include <string.h>

/**** define the UART you are using  ****/

extern UART_HandleTypeDef huart1;

#define uart &huart1


/* put the following in the ISR 

extern void Uart_isr (UART_HandleTypeDef *huart);

*/

/****************=======================>>>>>>>>>>> NO CHANGES AFTER THIS =======================>>>>>>>>>>>**********************/


ring_buffer tam_buffer = { { 0 }, 0, 0};
ring_buffer *_tam_buffer;

void Ringbuf_init(void)
{
	_tam_buffer = &tam_buffer;
	_tam_buffer->readIndex = 0;
	_tam_buffer->writeIndex = 0;
}



char Uart_read(void)
{
	 if (!IsEmpty()) {
	    char data = _tam_buffer->buffer[_tam_buffer->readIndex];
	    _tam_buffer->readIndex = (_tam_buffer->readIndex + 1) % UART_BUFFER_SIZE;
	    return data;
	  }
	  return '\0'; // Return null character if buffer is empty
}

/* writes a single character to the uart and increments head
 */
void Uart_write(uint8_t data)
{
  if (!IsFull()) {
	  _tam_buffer->buffer[_tam_buffer->writeIndex] = data;
	  _tam_buffer->writeIndex = (_tam_buffer->writeIndex + 1) % UART_BUFFER_SIZE;
  }
}

/* checks if the new data is available in the incoming buffer
 */
int IsDataAvailable(void)
{
	  if (_tam_buffer->writeIndex >= _tam_buffer->readIndex) {
	    return _tam_buffer->writeIndex - _tam_buffer->readIndex;
	  } else {
	    return (UART_BUFFER_SIZE - _tam_buffer->readIndex) + _tam_buffer->writeIndex;
	  }
}


uint8_t IsFull(void)
{
	return ((_tam_buffer->writeIndex + 1) % UART_BUFFER_SIZE) == _tam_buffer->readIndex;
}


uint8_t IsEmpty(void)
{
	return _tam_buffer->readIndex == _tam_buffer->writeIndex;
}
/* sends the string to the uart
 */
void Uart_sendstring (unsigned char *s)
{
	while(*s) Uart_write(*s++);
}



