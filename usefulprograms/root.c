#include <stdio.h>
#include <math.h>

int main(int argc, char *argv) {
	double num;
	double root;
	printf("Enter a number: ");
	scanf("%lf", &num);
	printf("Enter a root: ");
	scanf("%lf", &root);
	printf("%.20f\n", (double)pow(num, 1/root));
}
