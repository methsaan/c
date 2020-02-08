#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	char digits[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
	int num;
	printf("Enter number from 1-10000: ");
	scanf("%d", &num);
	char romNumeral[20] = "";
	int pVal[10][4] = {{0, -1, -1, -1}, {0, 0, -1, -1}, {0, 0, 0, -1}, {0, 1, -1, -1}, {1, -1, -1, -1}, {1, 0, -1, -1}, {1, 0, 0, -1}, {1, 0, 0, 0}, {0, 2, -1, -1}, {2, -1, -1, -1}};
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
				romNumeral[cnt] = pValTemp[x] == -1 ? '\0' : digits[6+pValTemp[x]];
				cnt++;
			}
		}
	}
	printf("%s\n", romNumeral);
	// romNum: 
	// tempNum: 4523
	// idx: 4
	// pValtemp: {1, -1, -1, -1}
}
