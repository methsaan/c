#include <stdio.h>

int main(int argc, char *argv) {
	long double x;
	printf("Enter a repeating decimal: ");
	scanf("%lf", &x);
	long double x_X_100 = x*100;
	printf("%lf\n", x_X_100-x);
	printf("____________   =   %lf \n\n", (x_X_100-x)/99);
	printf("%lf\n", 99);
}
