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

unsigned char hour;
unsigned char min;
unsigned char sec;


/**
 * there two function BCDToDecimal, DecimalToBCD in rtc driver module
 * I use it in getTime , setTime function (built in)
 */
int main(){
	LCD_init();//initialize lcd
	RTC_init();//initialize RTC , i2c

	setTime(1 , 59 ,50); //hour =1 , min = 59 , sec =50

	while(1){

		getTime(&hour , &min , &sec);//read hour , tmp_bcd , second
		LCD_intToString( hour , min , sec);//display the  hour , min , sec on lcd
		_delay_ms(100);//wait 100 msec
		LCD_clearScreen();//clean lcd


	}

//	LCD_intToString(DecimalToBCD(1),DecimalToBCD(33),DecimalToBCD(34));
//	//LCD_intToString(de)
//	while(1);

	return 0;
}



