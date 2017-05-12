/* Author: Liam Lawrence and Elijah Hodges
 * Date: 5.11.17
 * Watches over the magnets and can tell if any of them are triggered
 */

#include<avr\io.h>
#include<util\delay.h>
#include "i2c.h"

// Initializes I2C module
void I2C_Init() {
    TWSR=0x00; //set presca1er bits to zero
    TWBR=0x46; //SCL frequency is 100K for XTAL = 7.3728M
    TWCR=0x04; //enab1e TWI module
}

// Generates start condition for I2C
// Start Condition: SDA goes low when SCL is high
void I2C_Start() {
    TWCR = ((1<<TWINT) | (1<<TWSTA) | (1<<TWEN));
    while (!(TWCR & (1<<TWINT)));
}

// Generates stop condition for I2C
// Start Condition: SDA goes high when SCL is high
void I2C_Stop(void) {
    TWCR = ((1<< TWINT) | (1<<TWEN) | (1<<TWSTO));
    _delay_us(10) ; //wait for a short time
}

// Sends a byte on SDA line using I2C protocol
// 8-bit data is sent bit-by-bit on each clock cycle
// MSB(bit) is sent first and LSB(bit) is sent last
// Data is sent when SCL is low
// Argument: 8-bit data to send over I2C
void I2C_Write(unsigned char dat) {
    TWDR = dat ;
    TWCR = ((1<< TWINT) | (1<<TWEN));
    while (!(TWCR & (1 <<TWINT)));
}

// Receive a byte on SDA line using I2C protocol
// 8-bit data is received bit-by-bit each clock and packed into Byte
// MSB(bit) is received first and LSB(bit) is received last
// Argument: Acknowledgement for the Ninth clock cycle
// Return Value: unsigned char(received byte)
unsigned char I2C_Read(unsigned char ack) {
    TWCR = ((1<< TWINT) | (1<<TWEN) | (ack<<TWEA));
    while ( !(TWCR & (1 <<TWINT)));
    return TWDR;
}