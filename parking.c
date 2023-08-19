#include <reg51.h>
sbit IRSensor = P2^0; // Infrared sensor connected to P2.0
sbit LDR = P2^1; // Light dependent resistor connected to P2.1
sbit LED1 = P1^0; // First LED connected to P1.0
sbit LED2 = P1^1; // Second LED connected to P1.1
sbit LED3 = P1^2; // Third LED connected to P1.2
sbit LED4 = P1^3; // Fourth LED connected to P1.3
sbit Buzzer = P3^0; // Buzzer connected to P3.0
void delay_ms(unsigned int time_ms)
{
unsigned int i,j;
for(i=0;i<time_ms;i++)
for(j=0;j<112;j++);
}
void main()
{
unsigned int distance;

unsigned char intensity;
TMOD = 0x01; // Timer 0, mode 1
TH0 = 0x3C; // Set timer high value
TL0 = 0xB0; // Set timer low value
TR0 = 1; // Start the timer
while(1)
{
distance = IRSensor * TL0; // Calculate distance using IR sensor
intensity = 255 - (int)LDR; // Calculate intensity using LDR
if (distance <= 10)
{
LED1 = 1; // Turn on first LED
LED2 = 1; // Turn on second LED
LED3 = 1; // Turn on third LED
LED4 = 1; // Turn on fourth LED
Buzzer = 0; // Turn on Buzzer
}

else
{
LED1 = 0; // Turn off first LED

LED2 = 0; // Turn off second LED
LED3 = 0; // Turn off third LED
LED4 = 0; // Turn off fourth LED
Buzzer =1;
}

}
}