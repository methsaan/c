#include <stdio.h>
#include <math.h>

int main(int argc, char *argv) {
	double a;
	double b;
	double c;
	printf("Enter a: ");
	scanf("%lf", &a);
	printf("Enter b: ");
	scanf("%lf", &b);
	c = sqrt(pow(a, 2) + pow(b, 2));
	printf("Hypotenuse: %.15f\n", c);
}
