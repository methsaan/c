#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
	srand(time(NULL));
	int number;
	int numOfOperands;
	printf("Enter a number: ");
	scanf("%d", &number);
	printf("Enter number of operands (can't be more than %d): ", number/2);
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
	for (int x = 0; x < (int)(sizeof(operands)/sizeof(*operands))/2+1; x++) {
		int range = rand()%(number/numOfOperands-1)+1;
		while (1) {
			int rand1 = rand()%cnt;
			int rand2 = rand()%cnt;
			if (operands[rand2]-range > 0) {
				operands[rand1] += range;
				operands[rand2] -= range;
				break;
			}
		}
	}
	for (int x = 0; x < sizeof(operands)/sizeof(*operands); x++) {
		printf("%d%s", operands[x], x != sizeof(operands)/sizeof(*operands)-1 ? " + " : " = ");
	}
	printf("%d\n", number);
}
