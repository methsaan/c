#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv){
	char string[100];
	int len = 0;
	printf("Enter a string: ");
	fgets(string, 100, stdin);
	for (int x = 0; x < 100; x++){
		len++;
		if ((!isdigit(string[x])) && (!isalpha(string[x])) && (string[x] != 32)){
			break;
		}
	}
	len--;
	printf("Your string: %s", string);
	printf("length: %d\n", len);
	char backward[len];
	for (int x = 0; x < len; x--){
		backward[x] = string[len-x];
	}
	for (int x = 0; x < sizeof(backward)/sizeof(*backward); x++){
		printf("%c", backward);
	}
	printf("\n");
}
