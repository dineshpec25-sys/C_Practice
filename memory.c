#include <stdio.h>

int main() {
    int x = 5;
    int *p = &x;  // p stores the ADDRESS of x

    printf("value of x = %d\n", x);
    printf("address of x = %p\n", &x);
    printf("value of p = %p\n", p);
    printf("value AT the address p points to = %d\n", *p);

    return 0;
}
