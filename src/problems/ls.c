#include <stdio.h>
#include <dirent.h>

int main()
{
    DIR *dir = opendir(".");
    if(dir == NULL)
    {
        puts("Cannot open directory");
        return 1;
    }

    struct dirent *entry;
    while((entry = readdir(dir)) != NULL)
    {
        printf("%s\n", entry->d_name);
    }

    closedir(dir);
    return 0;
}
