#include <stdio.h>
#include <string.h>

int main()
{
    char in[1000];
    scanf("%999s", in);

    char tar[10];

    for(int i = 0; in[i] != '\0'; i++)
    {
        if(in[i] == 'C')
        {
            int count = 0;
            for(int j = i; j < i+9; j++)
            {
                if(tar[count-1] == 'N')
                {
                    tar[count++] = '0';
                    continue;
                }
                tar[count++] = in[j];
            }
            tar[count] = '\0';

            if(strcmp(tar, "CMD:R_OFF") == 0)
                printf("Red_Off\n");
            else if(strcmp(tar, "CMD:G_OFF") == 0)
                printf("Green_Off\n");
            else if(strcmp(tar, "CMD:B_OFF") == 0)
                printf("Blue_Off\n");
            else if(strcmp(tar, "CMD:R_ON0") == 0)
                printf("Red_On\n");
            else if(strcmp(tar, "CMD:G_ON0") == 0)
                printf("Green_On\n");
            else if(strcmp(tar, "CMD:B_ON0") == 0)
                printf("Blue_On\n");

            i += 7;

        }
    }
}