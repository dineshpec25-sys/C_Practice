volatile unsigned char *pinb =
    (volatile unsigned char *)0x23;

volatile unsigned char *ddrb =
    (volatile unsigned char *)0x24;

volatile unsigned char *portb =
    (volatile unsigned char *)0x25;


int main(void)
{
    /*
       PB6 → LED → output
       PB7 → Push button → input
    */

    // PB6 = output
    *ddrb |= (1 << 6);

    // PB7 = input
    *ddrb &= ~(1 << 7);

    // Enable internal pull-up on PB7
    *portb |= (1 << 7);

    // LED initially OFF
    *portb &= ~(1 << 6);


    while (1)
    {
        // Button pressed → PB7 becomes LOW
        if ((*pinb & (1 << 7)) == 0)
        {
            // LED ON
            *portb |= (1 << 6);
        }
        else
        {
            // LED OFF
            *portb &= ~(1 << 6);
        }
    }
}
