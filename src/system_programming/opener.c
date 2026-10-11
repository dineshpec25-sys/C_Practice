#include <stdio.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
    char path[] = "/home/acer/C_Practice/src/system_programming/out.txt";
    long fd = syscall(SYS_open, path, O_RDONLY);
    printf("fd = %ld\n", fd);
    return 0;
}
