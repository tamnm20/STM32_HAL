/*
 * console.c
 *
 *  Created on: Mar 26, 2025
 *      Author: MCNEX
 */

#include "Ringbuffer.h"
#include "console.h"

extern RingBuffer_t USB_RxBuffer;
unsigned int  LinePos;
char LineBuffer[LINE_BUFFER_LENGTH];

char ConsoleGetLine(void){
	uint8_t Key;
	if (!RingBuffer_IsEmpty(&USB_RxBuffer)) {
		Key = RingBuffer_Read(&USB_RxBuffer);
	  // Xử lý data...
	}
//	if (SerialComm_GetSize(CONOLE_NUM) <= 0) {
//		return 0;
//	}

//	Key = SerialComm_Getc(CONOLE_NUM);

	switch (Key) {
//		case BACKSPACE:
//		case DEL:
//			if (LinePos == 0)
//				break;
//
//			LineBuffer[--LinePos] = 0x00;
//			__io_putchar(BACKSPACE);
//			__io_putchar(SPACE);
//			__io_putchar(BACKSPACE);
//			//fflush(stdout);
//			break;
//		case ESC:
//			//LinePos = 0;
//			//LineBuffer[LinePos] = 0x00;
//			break;
//		case '[':
//			break;
		case CR:
			//LineBuffer[LinePos++] = Key;
			LinePos = 0;
			//curr_index = prev_index;
			//Key = LF;
			break;
//		case UP_ARROW:
//			//HistoryCommandProc(DIR_UP, LineBuffer);
//			//printf("%s", LineBuffer);
//			break;
//		case DOWN_ARROW:
//			//HistoryCommandProc(DIR_DOWN, LineBuffer);
//			//printf("%s", LineBuffer);
//			break;
		default:
			LineBuffer[LinePos++] = Key;
			LineBuffer[LinePos] = 0x00;
			//__io_putchar(Key);
			//(void)HAL_UART_Transmit( &huart1, (uint8_t *)&Key, 1, 10 );
			fflush(stdout);
			break;
	}

	return	Key;
}
