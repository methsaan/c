#include <stdio.h>
#include <math.h>

int main(int argc, char *argv) {
	double a;
	double a2;
	double b;
	double c;
	printf("Enter width of rectagular prism: ");
	scanf("%lf", &a);
	printf("Enter length of rectagular prism: ");
	scanf("%lf", &b);
	printf("Enter height of rectagular prism: ");
	scanf("%lf", &a2);
	c = sqrt(pow(a, 2) + pow(b, 2));
	c = sqrt(pow(c, 2) + pow(a2, 2));
	printf("Length across rectangular prism: %.15f\n", c);
} 
