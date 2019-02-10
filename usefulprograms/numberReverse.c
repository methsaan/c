#include <stdio.h>

int main(int argc, char *argv) {
	int num;
	int backward;
	printf("Enter a number: ");
	scanf("%d", &num);
	backward = num*8+num%10;
	printf("%d\n", backward);
}
