#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	char digits[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
	char num[4];
	printf("Enter number from 1-1000: ");
	scanf("%s", num);
	int decDigits[4] = {num[0]-'0', num[1]-'0', num[2]-'0', num[3]-'0'};
	char romanNumeral[36];
	for (int x = 0; x < digits[0]; x++) {
		romanNumeral[x] = 'M';
	}
	for (int x = digits[0]; x < digits[1]; x++) {
		romanNumeral[x] = 'C';
	}
	for (int x = digits[0]+digits[1]; x < digits[2]; x++) {
		romanNumeral[x] = 'X';
	}
	for (int x = digits[0]+digits[1]+digits[2]; x < digits[3]; x++) {
		romanNumeral[x] = 'I';
	}
	printf("%s\n", romanNumeral);
}
