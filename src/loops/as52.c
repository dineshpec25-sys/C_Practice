// i want to write a loop to print number from 5 to 1

// assign a variable = 5
// for condition(the number less than or equal to 1 and 
// it needs to decrement)
//     print the variable

#include<stdio.h>

int main(){
    int num = 5;
    for(num ; num >= 1 ;num--){
        printf("%d\n", num);
    }
    return 0;
}