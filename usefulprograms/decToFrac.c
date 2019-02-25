#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int numOfDigits(int num) {
	int count = 0;
	while (num > 0) {
		num = num / 10;
		count++;
	}
	return count;
}
int main(int argc, char *argv) {
	double x;
	printf("Enter a number with repeated digits: ");
	scanf("%lf", &x);
	int repeating;
	printf("Enter the repeating part of the number: ");
	scanf("%d", &repeating);
	int repeatingLength = numOfDigits(repeating);
	double x_X_100 = x * 100;
	for (int x = 4+repeatingLength; x < 7+(repeatingLength*3); x += repeatingLength) {
		x_X_100 += repeating * pow(10, -x);
	}
	printf("  __\n");
	printf("%d.%d  =  %d / %d\n", (int)x, repeating, (int)round(x_X_100-x), 99);
}
