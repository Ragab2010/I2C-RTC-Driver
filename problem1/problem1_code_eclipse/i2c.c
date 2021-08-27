/*
 * i2c.c
 *
 *  Created on:
 *      Author:
 */

#include "i2c.h"

void I2C_init(){
	//Frequncy eqaul 100KHz
	TWBR = 0X47;
	TWSR = 0X00;
	TWCR = 0x04;
	//TWPS1 TWPS0 = 00   -- no Prescaler

	TWCR = (1<<TWEN);  //Enable the TWI module

}
void I2C_initSlave(unsigned char slaveAddr){
	TWCR = (1<<TWEN);  //Enable the TWI module FRIST IN SLAVE MODE
	TWAR = slaveAddr;
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);//ENABLE , CLAER FLAG , SEND ACK
	//WE CAN REMOVE ACK

}
void I2C_listen(){

	while(!(TWCR & (1<<TWINT))); //IS LISIN TO CALL FROM MASTER TO ACK
}


void I2C_start(){
	TWCR = (1<<TWEN) | (1<<TWINT)| (1<<TWSTA);
	//Enable the TWI module
	// make flag be zero
	//Transmit START bit on SDA bus

	while(!(TWCR & (1<<TWINT))); //(start bit is send successfully)
}
void I2C_stop(){
	TWCR = (1<<TWEN)|(1<<TWINT)|(1<<TWSTO);
	//Enable the TWI module
	// make flag be zero
	//Transmit START bit on SDA bus


}

void I2C_write(unsigned char byte){
	TWDR = byte; // assign byte to DATA REGISTER
	TWCR = (1<<TWINT)|(1<<TWEN);
	// make flag be zero
	//Enable the TWI module

	while(!(TWCR & (1<<TWINT)));//(data is send successfully)
}

unsigned char I2C_read(unsigned char isLast){

	if(isLast == 0){//for more one byte
		TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
		// make flag be zero
		//Enable the TWI module
		//Transmit ACK bit on SDA bus

	}else{//for one byte
		TWCR = (1<<TWINT)|(1<<TWEN);
		// make flag be zero
		//Enable the TWI module
	}


	while(!(TWCR & (1<<TWINT))); //(data received successfully)

	return TWDR ; // return byte from the DATA REGISTER
}
