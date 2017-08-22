/*
 * Keypad.c
 *
 * Created: 05-05-2017 13:04:54
 *  Author: Etiq Technologies
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"

char key()
{
        char a;
        PORTA = 0X0E;
        a = PINA & 0XF0;
		if((PORTA&0x0F) == 0x0E){
        switch(a)
        {
            case 0X70: while((PINA & 0XF0) == a);
						return('*');
            case 0XB0: while((PINA & 0XF0) == a);
						return('0');
            case 0XD0: while((PINA & 0XF0) == a);
						return('#');
            case 0XE0: while((PINA & 0XF0) == a);
						return('D');
        }
		}		
       _delay_ms(10);
       
        PORTA = 0X07;
        a = PINA & 0XF0;
 		if((PORTA&0x0F) == 0x07){
       switch(a)
        {
            case 0X70: while((PINA & 0XF0) == a);
						return('1');
            case 0XB0: while((PINA & 0XF0) == a);
						return('2');
            case 0XD0: while((PINA & 0XF0) == a);
						return('3');
            case 0XE0: while((PINA & 0XF0) == a);
						return('A');
        }
		 }		 		
       _delay_ms(10);
	   
        PORTA = 0X0B;
        a = PINA & 0XF0;
		
		if((PORTA&0x0F) == 0x0B){
        switch(a)
        {
            case 0X70: while((PINA & 0XF0) == a);
						return('4');
            case 0XB0: while((PINA & 0XF0) == a);
						return('5');
            case 0XD0: while((PINA & 0XF0) == a);
						return('6');
            case 0XE0: while((PINA & 0XF0) == a);
						return('B');
			}					   
        }
       _delay_ms(10);
	    
        PORTA = 0X0D;
        a = PINA & 0XF0;
		if((PORTA&0x0F) == 0x0D){
        switch(a)
        {
            case 0X70: while((PINA & 0XF0) == a);
						return('7');
            case 0XB0: while((PINA & 0XF0) == a);
						 return('8');
            case 0XD0: while((PINA & 0XF0) == a);
						return('9');
            case 0XE0: while((PINA & 0XF0) == a);
						return('C');
        }
		}		
       _delay_ms(10);
	   
	   return('\0');
}

int main(void)
{
	char a;
	DDRA = 0x0F;
	lcd_init();
	CMD(0x80);
	StringData("KEYPAD TESTING");
	CMD(0xC0);
	
    while(1)
    {
       a = key();
       _delay_ms(250);
       if(a != '\0'){
		   CMD(0xC0);
           CharData(a);
	   }		   
    }
}