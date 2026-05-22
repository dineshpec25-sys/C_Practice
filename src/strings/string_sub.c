#include <stdio.h>
#include <stdlib.h>

char *bigint_sub(char *input_arr1, char *input_arr2,
                 int size_arr1, int size_arr2)
{
    int master_count =
        (size_arr1 > size_arr2) ? size_arr1 : size_arr2;

    char local_array1[master_count + 1];
    char local_array2[master_count + 1];

    /* left zero padding */
    for(int i = 0; i < master_count; i++)
    {
        if(i < master_count - size_arr1)
        {
            local_array1[i] = '0';
        }
        else
        {
            local_array1[i] =
                input_arr1[i - (master_count - size_arr1)];
        }
    }
    local_array1[master_count] = '\0';

    for(int i = 0; i < master_count; i++)
    {
        if(i < master_count - size_arr2)
        {
            local_array2[i] = '0';
        }
        else
        {
            local_array2[i] =
                input_arr2[i - (master_count - size_arr2)];
        }
    }
    local_array2[master_count] = '\0';

    /* compare and swap if needed */
    int check_interchange = 0;

    for(int i = 0; i < master_count; i++)
    {
        if(local_array1[i] < local_array2[i])
        {
            for(int j = 0; j < master_count; j++)
            {
                char temp = local_array1[j];
                local_array1[j] = local_array2[j];
                local_array2[j] = temp;
            }

            check_interchange = 1;
            break;
        }

        else if(local_array1[i] > local_array2[i])
        {
            break;
        }
    }

    /* subtraction */
    char *result = malloc(master_count + 1);

    int count = master_count;
    result[count--] = '\0';

    int digit_index = master_count - 1;
    int borrow = 0;

    for(int i = 0; i < master_count; i++)
    {
        int left_digit =
            (local_array1[digit_index] - '0') - borrow;

        int right_digit =
            local_array2[digit_index] - '0';

        borrow = 0;

        if(left_digit < right_digit)
        {
            left_digit += 10;
            borrow = 1;
        }

        result[count--] =
            (left_digit - right_digit) + '0';

        digit_index--;
    }

    /* add minus sign */
    if(check_interchange == 1)
    {
        result = realloc(result, master_count + 2);

        for(int i = master_count; i >= 0; i--)
        {
            result[i + 1] = result[i];
        }

        result[0] = '-';
    }

    return result;
}