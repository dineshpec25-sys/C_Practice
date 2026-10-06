#include "gpio.h"

volatile unsigned char* pi = (volatile unsigned char*)0x25;
void show(int dec)
{
  *pi = dec;
}

int main()
{
  for(int i = 0; i <5; i++)
  {
    MODE_SET('B',i,OUT);
  }
  uint8_t number;
  while(1)
  {
    for(number = 0; number < 256; number++)
    { 
      show(number);
      stay_still(500000);
    }
  }

}
