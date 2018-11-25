#include <stdio.h>

int main(int argc, char *argv){
	char str[100];
	printf("Type something: ");
	fgets(str, 100, stdout);
	fputs(str, stdin);
}
