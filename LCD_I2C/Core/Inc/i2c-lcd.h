/** 
Edit by modify: Ngoc Hang 
**/

#include "stm32f1xx_hal.h"
#define LCD_SETCGRAMADDR 0x40

typedef enum {
	LCD_SHIFT_LEFT,
	LCD_SHIFT_RIGHT
}LCD_ShiftTypeDef;

extern uint8_t heart[8];
extern uint8_t smiley[8];
extern uint8_t frownie[8];
extern uint8_t armsDown[8];
extern uint8_t armsUp[8];
extern uint8_t Tuan[8];

void lcd_init (void);   // initialize lcd

void lcd_send_cmd (char cmd);  // send command to the lcd

void lcd_send_data (char data);  // send data to the lcd

void lcd_send_string (char *str);  // send string to the lcd

void lcd_clear_display (void);	//clear display lcd

void lcd_goto_XY (int row, int col); //set proper location on screen

void lcd_createChar (uint8_t location, uint8_t charmap[]);   // Allows us to fill the first 8 CGRAM locations with custom characters

void LCD_ShiftDisplay(LCD_ShiftTypeDef shift_direc, uint8_t num);

