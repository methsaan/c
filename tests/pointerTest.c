#include <stdio.h>

int main(int argc, char *argv[]) {
	int x = 30;
	int *xPtr = &x;
	printf("%x\n", xPtr);
	printf("%p\n", xPtr);
}
