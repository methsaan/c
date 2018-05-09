#include <stdio.h>
#include <math.h>

int main(int argc, char* argv)
{
	char operator[20];
	double a;
	double b;
	double c;
	printf("%d\n", c);
	printf("Welcome to calculator. Options: add, sub, mul, div\n");
	printf("Enter operator: ");
	scanf("%s", operator);
	printf("Enter first number: ");
	scanf("%lf", &a);
	printf("Enter second number: ");
	scanf("%lf", &b);
	//if (operator == "add"){
	c = a + b;
	//}else if (operator == "sub"){
	//	c = a - b;
	//}else if (operator == "mul"){
	//	c = a * b;
	//}else if (operator == "div"){
	//	c = a / b;
	//}
	printf("%lf x %lf = %lf\n", a, b, c);
}
