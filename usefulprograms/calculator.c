#include <stdio.h>
#include <math.h>
#include <string.h>

int main(int argc, char* argv)
{
	int x;
	int y;
	char op[3];
	printf("Enter operator:(add, sub, mul, div, sqrt) ");
	scanf("%s", op);
	printf("Enter x: ");
	scanf("%d", &x);
	if (strcmp(op, "sqrt") != 0) {
		printf("Enter y: ");
		scanf("%d", &y);
	}
	if (strcmp(op, "add") == 0){
		printf("%d + %d = %d\n", x, y, x+y);
	}
	else if (strcmp(op, "sub") == 0){
		printf("%d - %d = %d\n", x, y, x-y);
	}
	else if (strcmp(op, "mul") == 0){
		printf("%d \u00D7 %d = %d\n", x, y, x*y);
	}
	else if (strcmp(op, "div") == 0){
		printf("%d \u00F7 %d = %f\n", x, y, (double)x/(double)y);
	}
	else if (strcmp(op, "sqrt") == 0){
		double xFlt = x + 0.000000;
		printf("%f\n", sqrt(x));
	}
	else {
		printf("");
	}
}
