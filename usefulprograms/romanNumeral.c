#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	char digits[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
	int digDec[] = {1000, 500, 100, 50, 10, 5, 1};
	int ranges[] = {1, 10, 100, 1000};
	int num;
	printf("Enter number from 1-1000: ");
	scanf("%d", &num);
	char romNumeral[20] = "";
	int pVal[][] = {{0, -1, -1, -1}, {0, 0, -1, -1}, {0, 0, 0, -1}, {0, 1, -1, -1}, {1, -1, -1, -1}, {1, 0, -1, -1}, {1, 0, 0, -1}, {1, 0, 0, 0}, {0, 2, -1, -1}, {2, -1, -1, -1}};
	int tempNum = num;
	int cnt = 0;
	while (1) {
		if (tempNum >= 1000 && tempNum < 10000) {
			int idx = tempNum / 1000;
			int pValTemp[4];
			for (int x = 0; x < 4; x++) {
				pValTemp[x] = pVal[idx][x];
			}
			for (int x = 0; x < 4; x++) {
				romNumeral[cnt] = digits[6]+pValTemp[x]
				cnt++;
			}
		}
	}
}
