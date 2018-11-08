#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv){
	char string[100];
	int len = 0;
	printf("Enter a string: ");
	fgets(string, 100, stdin);
	for (int x = 0; x < 100; x++){
		len++;
		if ((string[x] == ' ') || ((!isdigit(string[x])) && (!isalpha(string[x]))) ) {
			break;
		}
	}
	len--;
	printf("length: %d\n", len);
}
