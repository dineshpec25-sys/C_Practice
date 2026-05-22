#include <stdio.h>

struct area
{
    int length;
    int width;
};

int main()
{
    struct area a;
    printf("Enter the length of the rectangle:");
    scanf("%d", &a.length);
    printf("Enter the width of the rectangle:");
    scanf("%d", &a.width);
    int area = a.length * a.width;
    printf("The area of the rectangle is %d\n", area);
    return 0;
}