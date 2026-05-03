#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char* s_add(char *n1_arr, char *n2_arr, int s_n1, int s_n2);
void dis(char *r_arr);

int main()
{
    char num1_arr[51];
    char num2_arr[51];

    scanf("%50s", num1_arr);
    scanf("%50s", num2_arr);

    char *n1p = num1_arr;
    char *n2p = num2_arr;

    int a1_size = strlen(num1_arr);
    int a2_size = strlen(num2_arr);

    char *rp = s_add( n1p, n2p, a1_size, a2_size);
    
    dis(rp);
    
    free(rp);

    return 0;
    
}

char* s_add(char *n1_arr, char *n2_arr, int s_n1, int s_n2)
{
    int capacity = ( s_n1 > s_n2) ? s_n1 : s_n2 ;

    char l1_arr[capacity+1];
    char l2_arr[capacity+1];

    // Loacl Array 1
    int temp1 = s_n1-1;
    for(int k = capacity-1; k >= 0; k--)
    {
        if(temp1 < 0)
        {
            l1_arr[k] = '0';
            continue ;
        }
        l1_arr[k] = n1_arr[temp1--];
    }
    l1_arr[capacity] = '\0';

    //  Local Array 2
    int temp2 = s_n2-1;
    for(int k = capacity-1; k >= 0; k--)
    {
        if(temp2 < 0)
        {
            l2_arr[k] = '0';
            continue ;
        }
        l2_arr[k] = n2_arr[temp2--];
    }
    l2_arr[capacity] = '\0';

    char* result = malloc((capacity+1) * sizeof(char));  // Resulting Array
    int count = capacity;
    int i = capacity - 1; // Index for 1st array
    int j = capacity - 1; // Index for 2nd array
    int carry = 0;  // Carray storing variable

    result[count--] = '\0';
    
    for(int k = 0; k < capacity; k++)
    {
        int temp3 = l1_arr[i--] - '0';
        int temp4 = l2_arr[j--] - '0';

        int i_sum = temp3 + temp4 + carry;

        int last = i_sum % 10;
        carry = i_sum / 10;

        result[count--] = last + '0';
    }
    
    if(carry)
        {
            result = realloc( result, (capacity+2) * sizeof(char));
            
            char c_carry = carry + '0';
            for(int i = capacity; i >= 0; i--)
            {
                result[i+1] = result[i];
            }
            
            result[0] =  c_carry;
            carry = 0;
        }

    return result;
}

void dis(char *r_arr)
{
    for(int i = 0; r_arr[i] != '\0'; i++)
    {
        printf("%c", r_arr[i]);
    }
    printf("\n");
    return;
}