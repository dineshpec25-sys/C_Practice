#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char* s_add(char *n1_arr, char *n2_arr);
void dis(char *r_arr);

int main()
{
    char num1_arr[4] = "123";
    char num2_arr[4] = "923";
    char *n1p = num1_arr;
    char *n2p = num2_arr;
    char *rp = s_add( n1p, n2p);
    int a1_size = strlen(num1_arr);
    int a2_size = strlen(num2_arr);
    
    dis(rp);
    
    free(rp);
    
}

char* s_add(char *n1_arr, char *n2_arr)
{
    char* result = malloc(4 * sizeof(char));
    int count = 3;
    int carry = 0;
    
    result[count--] = '\0';
    
    for(int i = 2; i >= 0; i--)
    {
        int temp1 = n1_arr[i] - '0';
        int temp2 = n2_arr[i] - '0';
        
        int i_sum = temp1 + temp2 + carry;
        
        if(i_sum <= 9)
        {
            char c_sum = i_sum + '0';
            result[count--] = c_sum;
            continue ;
        }
        
        if(i != 0)
        {
            int last = i_sum % 10;
            char c_sum = last + '0';
            
            carry = i_sum / 10;
            
            result[count--] = c_sum;
        }
        
        else if(i == 0)
        {
            result = realloc( result, 5 * sizeof(char));
            
            int last = i_sum % 10;
            char c_sum = last + '0';
            
            carry = i_sum / 10;
            
            result[count--] = c_sum;
            
            char c_carry = carry + '0';
            for(int i = 3; i >= 0; i--)
            {
                result[i+1] = result[i];
            }
            count++;
            
            result[count--] =  c_carry;
        }
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