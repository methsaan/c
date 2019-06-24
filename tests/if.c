#include<stdio.h>
#include<string.h>

int main(int argc, char* argv) {
	char x[] = "s";
	char y[] = "a";
	if (strcmp(x, y) != 0) {
		printf("!\n");
	}
	if (strcmp(x, y) == 0) {
		printf("=\n");
	}
	return 0;
}
