#include<avr/io.h>
#include<util/delay.h>
void main()
{
DDRD=0b00000000;              //part D as input
DDRB=0b11111111;              //part b as output
PORTD=0b11111111;
int c;
while(1)
{
c=PIND;
if(c==0b11110000)//all sensors on table
PORTB=0b11111010;//move frwrd
if(c==0b11111000)//senosr 1 out
{
PORTB=0b11110101;//move rev
_delay_ms(300);
PORTB=0b11111001;//move ri8
_delay_ms(500);
}
if(c==0b11110100)//sensor 2 is out
{
PORTB=0b11110101;//move rev
_delay_ms(300);
PORTB=0b11110110;//move left
_delay_ms(500);
}
if(c==0b1110010)//sensor 3 is out
{
PORTB=0b11111010;//frwrd
_delay_ms(300);
PORTB=0b11111001;//ri8
_delay_ms(500);
}
if(c==0b11110001)//sensor 4 is out
{
PORTB=0b11111010;//frwrd
_delay_ms(300);
PORTB=0b11110110;//left
_delay_ms(500);
}
if(c==0b11111100)//sensor 1 &2 are out
{
PORTB=0b11110101;//rev
_delay_ms(300);
PORTB=0b11111001;//ri8
_delay_ms(500);
}
if(c==0b11111001)//sensors 1 & 4 are out
PORTB=0b11111001;//ri8
if(c==0b11110011)//sensors 3 & 4 are out
PORTB=0b11111010;//frwrd
if(c==0b11110110)//sensors 2 & 3 are out
PORTB=0b11110110;//left
if(c==0b11111110)//sensors 1 2 3 out
PORTB=0b11110110;//left
if(c==0b11110111)//sensors 2 3 4 out
PORTB=0b11110110;//left
if(c==0b11111011)//sensors 1 3 4 out
PORTB=0b11111001;//ri8
if(c==0b11111101)//sensors 1 2 4 out
PORTB=0b11111001;//ri8
}
}
	
