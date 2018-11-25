#include <stdio.h>

int main(int argc, char *argv){
	printf("sizeof(FILE): %d\n", sizeof(FILE));
	printf("sizeof(*stdin): %d\n", sizeof(*stdin));
	printf("sizeof(int): %d\n", sizeof(int));
	printf("sizeof(char): %d\n", sizeof(char));
	printf("sizeof(double): %d\n", sizeof(double));
	printf("sizeof(fopen(\"booltest.c\", \"w\")): %d\n", sizeof(fopen("booltest", "w")));
	printf("sizeof(long long int): %d\n", sizeof(long long int));
	printf("sizeof(float): %d\n", sizeof(float));
	printf("sizeof(short): %d\n", sizeof(short));
}
