#include <stdio.h>
#include <math.h>

int main(int argc, char *argv) {
	long double x;
	long double repeating;
	char repeatingstr[5];
	printf("Enter a number with repeating digits: ");
	scanf("%lf", &x);
	printf("Enter the part of the number that repeats: ");
	scanf("%lf", &repeating);
	sprintf(repeatingstr, "%d", repeating);
	long double x_X_100 = x*100;
	for (int i = 4; i < 10; i++) {
		x_X_100 += repeating* (pow(10, -(i*sizeof(repeatingstr))));
	}
	printf("%lf", x_X_100);
	printf(" - %lf", x);
	printf(" = %lf\n", x_X_100-x);
	//printf("%lf\n", x_X_100-x);
	//printf("____________   =   %lf \n\n", (x_X_100-x)/99);
	//printf("%lf\n", 99);
}
