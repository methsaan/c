#include <stdio.h>
#include <math.h>

int main(int argc, char *argv) {
	double a;
	double b2;
	double b;
	double c;
	printf("Enter a: ");
	scanf("%lf", &a);
	printf("Enter b: ");
	scanf("%lf", &b);
	printf("Enter b2: ");
	scanf("%lf", &b2);
	c = sqrt(pow(a, 2) + pow(b, 2));
	c = sqrt(pow(c, 2) + pow(b2, 2));
	printf("3D hypotenuse %.15f\n", c);
} 
