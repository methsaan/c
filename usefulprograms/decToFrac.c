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
	printf("Enter the repeating part of the number (max. length 3): ");
	scanf("%d", &repeating);
	int repeatingLength = numOfDigits(repeating);
	double x_X_100 = x * 100;
	double x_X_1000 = x * 1000;
	for (int y = 4+repeatingLength; y < 7+(repeatingLength*3); y += repeatingLength) {
		x_X_100 += repeating * pow(10, -y);
	}
	printf("%d.%d  =  %d%s / %d\n", (int)x, repeating, (int)round(x_X_100-x), repeatingLength == 3 ? "0" : "", repeatingLength < 3 ? 99 : 999);
}
