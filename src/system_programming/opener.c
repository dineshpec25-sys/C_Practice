#include <stdio.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char *path = argv[1];

    long fd = syscall(SYS_open, path, O_RDONLY);
    if (fd == -1) {
        printf("open failed\n");
        return 1;
    }

    char buf[100000];
    long n = syscall(SYS_read, fd, buf, 100000);
    syscall(SYS_write, 1, buf, n);
    syscall(SYS_close, fd);
    return 0;
}
