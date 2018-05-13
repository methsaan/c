#include <stdio.h>
#include <math.h>

int main(int argc, char* argv)
{
	char operator[3];
	double a;
	double b;
	double c;
	printf("Welcome to calculator. Options: add, sub, mul, div\n");
	printf("Enter operator: ");
	scanf("%s", operator);
	printf("Enter first number: ");
	scanf("%lf", &a);
	printf("Enter second number: ");
	scanf("%lf", &b);
	if (operator == "add"){
		c = a + b;
		printf("%lf + %lf = %lf\n", a, b, c);
	}else if (operator == "sub"){
		c = a - b;
		printf("%lf - %lf = %lf\n", a, b, c);
	}else if (operator == "mul"){
		c = a * b;
		printf("%lf x %lf = %lf\n", a, b, c);
	}else if (operator == "div"){
		c = a / b;
		printf("%lf / %lf = %lf\n", a, b, c);
	}else{
		printf("Invalid operator\n");
	}
	return(0);
}
