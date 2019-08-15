#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	char digits[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
	char num[4];
	printf("Enter number from 1-1000: ");
	scanf("%s", num);
	int decDigits[4] = {num[3]-'0', num[2]-'0', num[1]-'0', num[0]-'0'};
	char romanNumeral[36];
	int cnt = 0;
	for (; cnt < decDigits[0]; cnt++) {
		romanNumeral[cnt] = 'I';
	}
	for (; cnt < decDigits[1]; cnt++) {
		romanNumeral[cnt] = 'X';
	}
	for (; cnt < decDigits[2]; cnt++) {
		romanNumeral[cnt] = 'C';
	}
	for (; cnt < decDigits[3]; cnt++) {
		romanNumeral[cnt] = 'M';
	}
	printf("%s\n", romanNumeral);
}
