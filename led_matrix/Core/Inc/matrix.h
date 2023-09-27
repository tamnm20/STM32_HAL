/*
 * matrix.h
 *
 *  Created on: Sep 16, 2023
 *      Author: ADMIN
 */

#ifndef INC_MATRIX_H_
#define INC_MATRIX_H_

#include "stm32f1xx_hal.h"
void Init (void);
void Shiftbyte(unsigned char  data);
void SendAddrDat (unsigned char addr, unsigned char data);
void Print_Text(char text);
void Print_CharMatrix_LEFT(char text);
void Print_CharMatrix_RIGHT(char text);
void Print_StringMatrix(char *s);
void Print_StringMatrix_UP3(char *s);
void Print_StringMatrix_UP(char text);
void Print_StringMatrix_DOWN(char text);
#endif /* INC_MATRIX_H_ */
