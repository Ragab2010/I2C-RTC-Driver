/*
 * KEYPAD.h
 *
 *  Created on: ??�/??�/????
 *      Author: RAGAB
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_


#include "avr/io.h"
#include "util/delay.h"

#define KEYPAD_DDR DDRD
#define KEYPAD_CTRL PORTD
#define KEYPAD_PIN  PIND
#define COL 3
#define ROW 4
typedef unsigned char uint8;


unsigned char KEYRead();
unsigned char getTimeBCD();

#endif /* KEYPAD_H_ */
