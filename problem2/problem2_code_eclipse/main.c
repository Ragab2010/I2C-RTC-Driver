/*
 * main.c
 *
 *  Created on:
 *      Author:
 */

#include <avr/io.h>
#include <util/delay.h>
#include "rtc.h"
#include "lcdlib.h"
#include "KEYPAD.h"

unsigned char recieve_hour;
unsigned char recieve_min;
unsigned char recieve_sec;

unsigned char input_hour;
unsigned char input_min;
unsigned char input_sec;


/**
 * there function  getTimeBCD in KEYPAD driver module
 * I use it in convert from ascii number to BCD number
 * keypad 3 * 4 by using internal pull-up resistor
 */
int main(){
	LCD_init();//initialize lcd
	RTC_init();//initialize RTC , i2c

	LCD_displayString("welcome");//display welcome in lcd
	_delay_ms(300);//wait 300 msec
	LCD_clearScreen();//clean lcd
	LCD_displayString("H=");//now display H=  hint for user to enter the number of hour by keypad
	input_hour=getTimeBCD();//now getTimeBCD function get the number and convert it to BCD
	LCD_displayString(" M=");//now display M=  hint for user to enter the number of minute by keypad
	input_min=getTimeBCD(); //now getTimeBCD function get the number and convert it to BCD
	LCD_displayString(" S=");//now display S=  hint for user to enter the number of second by keypad
	input_sec=getTimeBCD();//now getTimeBCD function get the number and convert it to BCD
	_delay_ms(200);//wait 200 msec

	/*now set the hour , minute , second which the user enter to RTC*/
	setTime(input_hour , input_min , input_sec);
	LCD_clearScreen();//clean the lcd
	while(1){// infinite loop
		/*now get the hour , minute , second from RTC */
		getTime(&recieve_hour , &recieve_min , &recieve_sec);
		/*display the hour ,minute , second that's recieved from RTC*/
		LCD_intToString(recieve_hour , recieve_min , recieve_sec);
		_delay_ms(100);//wait 100 msec
		LCD_clearScreen();//clean the lcd
	}


	return 0;
}



