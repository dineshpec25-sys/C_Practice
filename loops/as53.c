// i want to print the sum of numbers from 1 to 5

// i wil assign a variable = 1
// and another variable = 0 to store the summing values during loop
// inside the for the condition will be the variable will be less than 6
//     sum of the prevous loop plus the current variable
// print outside the loop

#include<stdio.h>

int main(){
    int num = 1;
    int sum = 0;
    for(num ; num < 6 ;num++){
        sum = sum + num;
    }
    printf("%d\n", sum);
    return 0;
}