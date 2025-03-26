/*
 * console.h
 *
 *  Created on: Mar 26, 2025
 *      Author: MCNEX
 */

#ifndef APP_CONSOLE_H_
#define APP_CONSOLE_H_

#define BACKSPACE						0x08
#define SPACE							0x20
#define LF								0x0A
#define CR								0x0D
#define CNTLQ							0x11
#define CNTLS							0x13
#define CNTLZ							0x1A
#define ESC								0x1B
#define DEL								0x7F
#define UP_ARROW						0x41
#define DOWN_ARROW						0x42

#define LINE_BUFFER_LENGTH				1024 //Tam change for updateFW

char ConsoleGetLine(void);

#endif /* APP_CONSOLE_H_ */
