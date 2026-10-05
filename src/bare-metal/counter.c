#include "gpio.h"
#include "7seg.h"

int main()
{
  uint8_t n = 0;
  uint8_t r;

  GIVE_OUT('B',7,HIGH);
  GIVE_OUT('B',6,HIGH);
  MODE_SET('B',7,OUT);   // 13 LSB common
  MODE_SET('B',6,OUT);   // 12 MSB common

  while (1)
  {
    for (r = 0; r < 100; r++)
    {
      GIVE_OUT('B',7,HIGH);
      GIVE_OUT('B',6,HIGH);
      clear_all();
      seg_7(n / 10);
      GIVE_OUT('B',6,LOW);
      stay_still(2000);

      GIVE_OUT('B',6,HIGH);
      clear_all();
      seg_7(n % 10);
      GIVE_OUT('B',7,LOW);
      stay_still(2000);
    }

    n++;
    if (n == 100)
    {
      n = 0;
    }
  }
}
