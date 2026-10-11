#include <unistd.h>
#include <sys/syscall.h>

int main()
{
	syscall(SYS_write, 1, "hello\n", sizeof("hello\n")-1);
	return 0;
}
