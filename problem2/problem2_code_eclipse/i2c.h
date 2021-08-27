/*
 * i2c.h
 *
 *  Created on:
 *      Author:
 */

#ifndef I2C_H_
#define I2C_H_

#include <avr/io.h>

void I2C_init();
void I2C_initSlave(unsigned char slaveAddr);
void I2C_listen();
void I2C_start();
void I2C_stop();
void I2C_write(unsigned char byte);
unsigned char I2C_read(unsigned char isLast);


#endif /* I2C_H_ */
