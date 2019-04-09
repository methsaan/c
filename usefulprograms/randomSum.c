#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv) {
	srand(time(NULL));
	double number;
	int operations;
	double remainder;
	double average;
	printf("Enter a number: ");
	scanf("%lf", &number);
	remainder = (double)number;
	printf("Enter the number of operations: ");
	scanf("%d", &operations);
	double sum[operations];
	average = number/operations;
	printf("%f\n", remainder);
	double range;
	for (int x = 0; x < operations-1; x++) {
		range = (rand()%5)+8.0;
		sum[x] = average + (double)(rand()%(int)range)-range/2;
		remainder = remainder - sum[x];
		printf("%f + ", sum[x]);
	}
	printf("%f\n", remainder);
}
