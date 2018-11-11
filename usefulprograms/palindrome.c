#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv){
	char string[100];
	int len = 0;
	printf("Enter a string: ");
	scanf("%s", string);
	for (int x = 0; x < 100; x++){
		len++;
		if ((!isdigit(string[x])) && (!isalpha(string[x])) && (string[x] != 32)){
			break;
		}
	}
	len--;
	char backward[100];
	int y = 0;
	for (int x = len-1; x > -1; x--){
		backward[y] = string[x];
		y++;
	}
	printf("%s\n", strcmp(backward, string) == 0 ? "Your word is a palindrome" : "Your word is not a palindrome");
}
