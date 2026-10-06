#include "address.h"

#define NO_KEY 255

static const uint8_t key_table[16] = {
   1,  2,  3, 10,
   4,  5,  6, 11,
   7,  8,  9, 12,
  14,  0, 15, 13
};

void keypad_init()
{
  uint8_t i;

  for (i = 0; i < 4; i++)
  {
    GIVE_OUT('A', i, HIGH);
    MODE_SET('A', i, OUT);
  }

  for (i = 4; i < 8; i++)
  {
    MODE_SET('A', i, IN);
    GIVE_OUT('A', i, HIGH);
  }
}

uint8_t scan()
{
  uint8_t col, row;

  for (col = 0; col < 4; col++)
  {
    GIVE_OUT('A', col, LOW);
    stay_still(50);

    for (row = 0; row < 4; row++)
    {
      if (TAKE_IN('A', row + 4, PULLUP) == 1)
      {
        GIVE_OUT('A', col, HIGH);
        return row * 4 + col;
      }
    }

    GIVE_OUT('A', col, HIGH);
  }

  return NO_KEY;
}

void show(uint8_t v)
{
  uint8_t i;

  for (i = 0; i < 4; i++)
  {
    GIVE_OUT('C', i, (v >> i) & 1);
  }
}

int main()
{
  uint8_t last = NO_KEY;
  uint8_t now;
  uint8_t i;

  keypad_init();

  for (i = 0; i < 4; i++)
  {
    MODE_SET('C', i, OUT);
  }
  show(0);

  while (1)
  {
    now = scan();

    if (now != NO_KEY && last == NO_KEY)
    {
      stay_still(20000);
      if (scan() == now)
      {
        show(key_table[now]);
      }
      else
      {
        now = NO_KEY;
      }
    }
    else if (now == NO_KEY && last != NO_KEY)
    {
      stay_still(20000);
    }

    last = now;
  }
}
