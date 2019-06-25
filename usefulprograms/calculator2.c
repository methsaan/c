#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// +, -, x, /, ^, r, hyp, circc, circa
int main(int argc, char* argv[])
{
	const double PI = 3.141592653589793238;
	double x = atof(argv[1]);
	double y = argc == 4 ? atof(argv[3]) : 0;
	char *op = (char*)malloc(1 * sizeof(char));
	sprintf(op, "%s", argv[2]);
	if ((strcmp(op, "circc") == 0 || strcmp(op, "circa") == 0) && argc == 4) {
		printf("Too many operands\n");
		return 0;
	}
	if (op[0] == '+') {
		printf("%f + %f = %f\n", x, y, x+y);
	}
	if (op[0] == '-') {
		printf("%f - %f = %f\n", x, y, x-y);
	}
	if (op[0] == 'x') {
		printf("%f x %f = %f\n", x, y, x*y);
	}
	if (op[0] == '/') {
		printf("%f / %f = %f\n", x, y, x/y);
	}
	if (op[0] == '^') {
		printf("%f ^ %f = %f\n", x, y, pow(x, y));
	}
	if (op[0] == 'r') {
		printf("          _____\n");
		printf("%f /    \n", y);
		printf("        V %f \t= \t%f\n", x, pow(x, 1/y));
	}
	if (strcmp(op, "hyp") == 0) {
		printf("c = %f\n", sqrt(pow(x, 2)+pow(y, 2)));
	}
	if (strcmp(op, "circc") == 0) {
		printf("c = %f\n", 2*PI*x);
	}
	if (strcmp(op, "circa") == 0) {
		printf("a = %f\n", PI*pow(x, 2));
	}
}
