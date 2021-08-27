/*
 * lcdlib.h
 *
 *  Created on:
 *      Author:
 */

#ifndef LCDLIB_H_
#define LCDLIB_H_


#include "avr/io.h"
#include "avr/delay.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define RS PB0
#define RW PB1
#define E  PB2
#define LCD_CTRL_PORT PORTB
#define LCD_CTRL_PORT_DIR DDRB
#define LCD_DATA_PORT PORTA
#define LCD_DATA_PORT_DIR DDRA

void LCD_init();
void LCD_command(unsigned char command);
void LCD_Data(unsigned char data);
void LCD_displayString(unsigned char *str );
void LCD_displayCharacter(unsigned char Byte );
void LCD_intToString(unsigned char hour , unsigned char min , unsigned char sec);
void LCD_clearScreen(void);
void LCD_displayStringRowCol(unsigned char row , unsigned char col , unsigned char *str );


#endif /* LCDLIB_H_ */
