/* This program receive value from a PC and transmit back to PC */

#include <reg52.h>
                  
void USART_Init(void);
void USART_Transmit(unsigned char);
unsigned char USART_Recv();

void main()
{
    
        USART_Init();       
        while(1) 
        {
                x=USART_Recv();
                USART_Transmit(x);
        }
}

/* INITIALIZE SERIAL PORT */
void USART_Init(void)                    
{
        TMOD = 0x20;       // For Timer 1, mode 2 - Auto reload mode select
        SCON = 0x50;     // SERIAL MODE 1, 8-DATA BIT 1-START BIT, 1-STOP BIT, REN ENABLED
        TH1 = 0xFD;        // Baud rate of 9600
        TR1 = 1;           // START TIMER
}

void USART_Transmit(unsigned char serialdata)
{
        SBUF = serialdata;   // LOAD DATA TO SERIAL BUFFER REGISTER
        while(TI == 0);      // WAIT UNTIL TRANSMISSION TO COMPLETE
        TI = 0;              // CLEAR TRANSMISSION INTERRUPT FLAG
}

unsigned char USART_Recv()
{
         while(RI==0);
         RI=0;    
         return SBUF;       
}