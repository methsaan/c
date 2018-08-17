#include <stdio.h>
#include <math.h>
#include <string.h>

int main(int argc, char* argv)
{
	int x;
	int y;
	char op[3];
	printf("Enter operator:(add, sub, mul, div) ");
	scanf("%s", op);
	printf("Enter x: ");
	scanf("%d", &x);
	printf("Enter y: ");
	scanf("%d", &y);
	if (strcmp(op, "add") == 0){
		printf("%d\n", x+y);
	}
	if (strcmp(op, "sub") == 0){
		printf("%d\n", x-y);
	}
	if (strcmp(op, "mul") == 0){
		printf("%d\n", x*y);
	}
	if (strcmp(op, "div") == 0){
		printf("%d\n", x/y);
	}else {
		double xFlt = x + 0.000000;
		printf("%f\n", sqrt(x));
	}
}
