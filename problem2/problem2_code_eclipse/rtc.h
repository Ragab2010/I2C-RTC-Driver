/*
 * rtc.h
 *
 *  Created on:
 *      Author:
 */

#ifndef RTC_H_
#define RTC_H_

#include "i2c.h"

void RTC_init();
void writeRTC(unsigned char address, unsigned char data);
unsigned char readRTC(unsigned char address);
unsigned char BCDToDecimal(unsigned char  bcdbyte);
unsigned char DecimalToBCD(unsigned char decimalbyte);
void setTime(unsigned char hour , unsigned char min , unsigned char sec);
void getTime(unsigned char *hour , unsigned char *min , unsigned char *sec);



#endif /* RTC_H_ */
