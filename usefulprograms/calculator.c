#include <stdio.h>
#include <math.h>

int main(int argc, char* argv)
{
	char operator[20];
	double a;
	double b;
	double c;
	printf("Welcome to calculator. Options: add, sub, mul, div\n");
	printf("Enter operator: ");
	scanf("%s", operator);
	printf("Enter first number: ");
	scanf("%f", &a);
	printf("Enter second number: ");
	scanf("%f", &b);
	if (operator == "add"){
		c = a + b;
		printf("%f + %f = %f\n", a, b, c);
	}
	if (operator == "sub"){
		c = a - b;
		printf("%f - %f = %f\n", a, b, c);
	}
	if (operator == "mul"){
		c = a * b;
		printf("%f x %f = %f\n", a, b, c);
	}
	if (operator == "div"){
		c = a / b;
		printf("%f / %f = %f\n", a, b, c);
	}
	if (operator != "add") && (operator != "sub") && (operator != "mul") && (operator != "div"){
		printf("Invalid operator\n");
	}
	return(0);
}
