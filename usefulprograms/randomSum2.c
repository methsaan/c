#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
	srand(time(NULL));
	int number;
	int numOfOperands;
	printf("Enter a number: ");
	scanf("%d", &number);
	printf("Enter number of operands: ");
	scanf("%d", &numOfOperands);
	int operands[numOfOperands];
	int numRemainder = number;
	int numOfOpRemainder = numOfOperands;
	int cnt = 0;
	while (numRemainder > 0) {
		int operand = numRemainder/numOfOpRemainder;
		numOfOpRemainder--;
		numRemainder -= operand;
		operands[cnt] = operand;
		cnt++;
	}
	printf("%d\n", cnt);
	for (int x = 0; x < (int)(sizeof(operands)/sizeof(*operands))/2+1; x++) {
		int range = rand()%(number/numOfOperands-1)+1;
		operands[rand()%cnt+1] += range;
		operands[rand()%cnt+1] -= range;
		printf("%d\n\n", range);
		for (int x = 0; x < sizeof(operands)/sizeof(*operands); x++) {
			printf("%d ", operands[x]);
		}
		for (long int x = 0; x < 200000000; x++) {
			;
		}
		printf("\n\n\n");
	}
}
