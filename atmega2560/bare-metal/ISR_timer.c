#include <stdint.h>
#include "driver/gpio.h"

#define on GIVE_OUT('A',0,HIGH)
#define off GIVE_OUT('A',0,LOW)

#define to (*(volatile unsigned char*) 0x22)

#define tccr0a (*(volatile unsigned char*)0x44) // register to control the mode
#define tcnt0 (*(volatile unsigned char*)0x46) // the actual counter
#define ocra (*(volatile unsigned char*)0x47) // the reference value
#define tifr (*(volatile unsigned char*)0x35) // the flag which indicates that the overflow
#define tccr0b (*(volatile unsigned char*)0x45) // to set a prescalar
#define timsk (*(volatile unsigned char*)0x6E) //Interrupt mask

void toggle_led()
{
  to ^= (1 << 0);
}

ISR(TIMER0_COMPA_vect)
{
	toggle_led();
}

int main()
{
  MODE_SET('A',0,OUT);
  tccr0a = 0x02; // CTC Mode
  tccr0b = 0x03; // 64 prescalar
  tcnt0 = 0x00; // making it zero
  ocra = 249; // (0 - 249 = 250) 4 x 10^-3 * 250 = 1sec
  timsk = 0x02; // setting the interrupt mask 
  volatile uint16_t count = 0;
  while(1)
  {
	 
  }
}
