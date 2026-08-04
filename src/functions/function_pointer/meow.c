#include <stdio.h>

void say_meow(void) {
    printf("Meow!\n");
}

int main(void) {
    void (*fn)(void);   // declare a function pointer
    fn = say_meow;        // point it at say_meow (no parens — we want the address, not a call)
    fn;                 // CALL through the pointer — this runs say_meow()
}