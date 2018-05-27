#include <stdio.h>
#include <math.h>

int main(int argc, char* argv)
{
	double x;
	double y;
	char op[1];
	printf("Enter operator:(+, -, x, /) ");
	scanf("%s", op);
	printf("Enter x: ");
	scanf("%f", &x);
	printf("Enter y: ");
	scanf("%f", &y);
	if (op == "+"){
		printf("%f + %f = %f\n", x, y, x+y);
	}
	if (op == "-"){
		printf("%f - %f = %f\n", x, y, x-y);
	}
	if (op == "x"){
		printf("%f x %f = %f\n", x, y, x*y);
	}
	if (op == "/"){
		printf("%f / %f = %f\n", x, y, x/y);
	}
}
