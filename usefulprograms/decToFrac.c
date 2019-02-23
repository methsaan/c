#include <stdio.h>
#include <math.h>

int main(int argc, char *argv) {
	double x;
	double repeating;
	char repeatingstr[5];
	printf("Enter a number with repeating digits: ");
	scanf("%lf", &x);
	printf("Enter the part of the number that repeats: ");
	scanf("%lf", &repeating);
	sprintf(repeatingstr, "%d", repeating);
	double x_X_100 = (int)(x*100);
	for (int i = sizeof(repeatingstr); i < 7; i += sizeof(repeatingstr)) {
		x_X_100 += repeating * (pow(10, -(i+1)));
	}
	printf("%f", x_X_100);
	printf(" - %f", x);
	printf(" = %f\n", x_X_100-x);
}
