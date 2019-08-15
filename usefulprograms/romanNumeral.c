#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	char digits[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
	char num[4];
	printf("Enter number from 1-1000: ");
	scanf("%s", num);
	int decDigits[4] = {num[3]-'0', num[2]-'0', num[1]-'0', num[0]-'0'};
	char romanNumeral[36] = {0x0};
	int cnt = 0;
	for (int cnt2 = 0; cnt2 < decDigits[3]; cnt2++) {
		romanNumeral[cnt++] = 'M';
	}
	printf("%d\n", cnt);
	for (int cnt2 = 0; cnt2 < decDigits[2]; cnt2++) {
		romanNumeral[cnt++] = 'C';
	}
	printf("%d\n", cnt);
	for (int cnt2 = 0; cnt2 < decDigits[1]; cnt2++) {
		romanNumeral[cnt++] = 'X';
	}
	printf("%d\n", cnt);
	for (int cnt2 = 0; cnt2 < decDigits[0]; cnt2++) {
		romanNumeral[cnt++] = 'I';
	}
	printf("%d\n", cnt);
	printf("%s\n", romanNumeral);
	//3835
	//MMMDCCCXXXV
}
