extern int write_in_asm(int, char*, int);
extern void exit_in_asm(int);

int begin() {
	int count = write_in_asm(1, "Hello!\n", 7);
	if (count == 7) exit_in_asm(0);
	exit_in_asm(1);
}


