#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int charToInt(char c) {
	return c - '0';
}

int main(int argc, char *argv[]) {
	char *num = argv[1];
	int length = -1;
	for (int x = 0; isdigit(num[x]); x++) {
		length++;
	}
	int armstrongTest = 0;
	for (int x = 0; x < length; x++) {
		armstrongTest += pow(charToInt(num[x]), length);
	}
	if (atoi(num) == armstrongTest) {
		printf("Armstrong number\n");
	}else {
		printf("Not an armstrong number\n");
	}
}
