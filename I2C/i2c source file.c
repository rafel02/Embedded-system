// Headers

#include<reg51.h>
#include<stdio.h>

// Macro

#define ACK 1
#define NO_ACK 0
#define EEPROM_ADDR 0xA0  // 24LC256 EEPROM address
 
// Variable

unsigned char i;
unsigned char EData[5];
unsigned char Data;

sbit SCL = P2^0; // connect to SCL pin (Clock)
sbit SDA = P2^1; // connect to SDA pin (Data)

// Function decalaration

void InitSerial(void);
void DelayMs(unsigned int);
void WriteI2C(unsigned char);
void Start(void);
void Stop(void);
void ReadBYTE(unsigned int);
void WriteBYTE(unsigned int);
unsigned char ReadI2C(bit);

// Function defination

/*—————————————
 * Initialize I2C
 */—————————————
void InitSerial(void)
{
	SCON = 0x52; // setup serial port control
	TMOD = 0x20; // hardware (9600 BAUD @11.0592MHZ)
	TH1 = 0xFD;  // TH1
	TR1 = 1;     // Timer 1 on
}

/*——————————-
 * start I2C
 */——————————-
void Start(void)
{
	SDA = 1;
	SCL = 1;
	SDA = 0;
	SCL = 0;
}

/*——————————-
 * stop I2C
 */——————————-
void Stop(void)
{
	SDA = 0;
	SCL = 1;
	SDA = 1;
}

/*——————————-
 * Write I2C
 */——————————-
void I2C_Write(unsigned char dat)
{
    unsigned char i;
    for(i=0; i<8; i++)
    {
        SDA = (dat & 0x80) ? 1 : 0;
        SCL = 1;
        SCL = 0;
        dat <<= 1;
    }
    SDA = 1;  // Release SDA for ACK
    SCL = 1;
    SCL = 0;  // Clock pulse for ACK
}
 
/* Read I2C */
unsigned char I2C_Read(bit ack)
{
    unsigned char i, dat = 0;
    SDA = 1;  // Release SDA for reading
    for(i=0; i<8; i++)
    {
        SCL = 1;
        dat <<= 1;
        dat |= SDA;
        SCL = 0;
    }
    SDA = !ack;  // Send ACK/NACK
    SCL = 1;
    SCL = 0;
    return dat;
}

void WriteEEPROM(unsigned int rg_addr)
{
    Start();
    I2C_Write(EEPROM_ADDR);
    I2C_Write((unsigned char)(rg_addr >> 8));  // Address MSB
    I2C_Write((unsigned char)rg_addr);         // Address LSB
}

void ReadEEPROM(unsigned int rg_addr)
{
	Start();
	WriteI2C(EEPROM);
	WriteI2C((unsigned char)(rg_addr>>8)&0xFF);
	WriteI2C((unsigned char)rg_ddr & 0xFF);
	Start();
		I2C_Write(LM75_ADDR | 1);  // Read mode

	EData[0] = ReadI2C(NO_ACK); // no acknolwedgement
	EData[1] = ReadI2C(NO_ACK);
	EData[2] = ReadI2C(NO_ACK);
	EData[3] = ReadI2C(NO_ACK);
	EData[4] = ReadI2C(NO_ACK);
	EData[5] = ReadI2C(NO_ACK);
	Stop();

	for(i=0;i<6;i++)
	{
		printf(“value = %c\n”,EData[i]); // display data */
		DelayMs(100);
	}

}

// Delay mS function. mSec Delay 11.0592 Mhz
void DelayMs(unsigned int count)
{
	unsigned int i;
	while(count)
	{
		i = 115;
		while(i>0) i–;
		count–;
	}
}

void main(void)
{
	InitSerial(); // Initialize serial port

	WriteEEPROM(0x0000)
	WriteI2C(‘A’); //Write Data’s Here
	WriteI2C(‘B’);
	WriteI2C(‘C’);
	WriteI2C(‘D’);
	WriteI2C(‘E’);
	WriteI2C(‘F’);
	Stop();
	DelayMs(10);

	ReadEEPROM(0x0000)
	DelayMs(10);

	while(1);
}