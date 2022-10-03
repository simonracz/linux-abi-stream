#include <stdio.h>
#include <string.h>

int call_write(int fd, char* message) {
	int len = strlen(message);
	int count;
	asm volatile ("movq $1, %%rax\n\t"
                      "movl %1, %%edi\n\t"
                      "movq %2, %%rsi\n\t"
                      "movl %3, %%edx\n\t"
                      "syscall"
                      : "=a"(count)
                      : "r" (fd), "r" (message), "r" (len));
	return count;
}

int main() {
	int count = call_write(fileno(stdout), "Hello!\n");
	if (count == 7) return 0;
	return 1;
}
