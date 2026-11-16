#include<stdio.h>
#include <unistd.h>

int main()
{
    int a = 50;

    printf("%d\nthe address %p\n", a, &a);
    sleep(2);
  printf("hi buddy!!!\n");
    return 0;
}
