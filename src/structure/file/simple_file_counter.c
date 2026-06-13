#include <stdio.h>

int main()
{
    FILE *fp;
    fp=fopen("/home/dinesh-p/C_Practice/src/structure/file/data/file.txt", "r");
    if(fp==NULL)
    {
        printf("File doesn't exist\n");
        return 1;
    }
    int content;
    int spaces=0;
    int new_line=0;
    int character=0;
    while((content=fgetc(fp)) != EOF)
    {
        character++;
        if(content == ' ')
            spaces++;
        else if(content == '\n')
            new_line++;
    }
    printf("Spaces: %d\n",spaces);
    printf("new Line: %d\n", new_line);
    printf("Character: %d\n", character);

    fclose(fp);
    return 0;
}