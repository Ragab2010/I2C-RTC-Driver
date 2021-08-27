/*
 * rtc.c
 *
 *  Created on:
 *      Author:
 */

#include "rtc.h"


void RTC_init(){
	I2C_init();
	I2C_start();
	I2C_write(0XD0);
	I2C_write(0X07);
	I2C_write(0x00);
	I2C_stop();
}
void writeRTC(unsigned char address, unsigned char data){

	I2C_start();
	I2C_write(0XD0);//bit0 =0 ; for write
	I2C_write(address);
	I2C_write(data);
	I2C_stop();
}

unsigned char readRTC(unsigned char address){
	unsigned char data;
	I2C_start();
	I2C_write(0XD0);//bit0 =0 ; for write
	I2C_write(0x00);
	I2C_stop();

	I2C_start();
	I2C_write(0XD1);//bit0 =1 ; for read
	I2C_write(address);
	data =I2C_read(1);
	I2C_stop();
	return data;
}

unsigned char BCDToDecimal(unsigned char  bcdbyte){
	return (( ( (bcdbyte & 0xF0)>>4) * 10) + (bcdbyte & 0x0F));
}

unsigned char DecimalToBCD(unsigned char decimalbyte){
	return (( ( (decimalbyte /10)<<4) ) | (decimalbyte % 10));
}

void setTime(unsigned char hour , unsigned char min , unsigned char sec){
	unsigned char tmp_bcd;
	I2C_start();
	I2C_write(0XD0);//bit0 =0 ; for write
	I2C_write(0x00);
	tmp_bcd=DecimalToBCD(sec);
	I2C_write(tmp_bcd);
	tmp_bcd=DecimalToBCD(min);
	I2C_write(tmp_bcd);
	tmp_bcd=DecimalToBCD(hour);
	I2C_write(tmp_bcd);
	I2C_stop();

}

void getTime(unsigned char *hour , unsigned char *min , unsigned char *sec){
	unsigned char tmp_bcd;
	I2C_start();
	I2C_write(0XD0);//bit0 =0 ; for write
	I2C_write(0x00);
	I2C_stop();

	I2C_start();
	I2C_write(0XD1);//bit0 =0 ; for write
	tmp_bcd =I2C_read(0);
	*sec=BCDToDecimal(tmp_bcd);
	tmp_bcd=I2C_read(0);
	*min=BCDToDecimal(tmp_bcd);
	tmp_bcd =I2C_read(1);
	*hour=BCDToDecimal(tmp_bcd);

	I2C_stop();

}

