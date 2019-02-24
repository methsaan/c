#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//
int main(int argc, char *argv) {
	double x;
	int repeating;
	int repeatingLength = 0;
	int temp = repeating;
	printf("Enter a number with repeating digits: ");
	scanf("%lf", &x);
	printf("Enter the part of the number that repeats: ");
	scanf("%lf", &repeating);
	while(temp != 0) {
	    temp /= 10;
	    repeatingLength++;
	}
	printf("%d\n\n\n", repeatingLength);
	double x_X_10 = (x*10);
	for (int a = 4; a < 7; a++) {
		x_X_10 += (double)repeating/pow(10, -(4*a+repeatingLength));
	}
	printf("%f", x_X_10);
	printf(" - %f", x);
	printf(" = %f\n", x_X_10-x);
}
