#include<stdio.h>
#include<math.h>

int main(int argc, char *argv){
	double c;
	double a;
	double b;
	double bsqrt;
	printf("Enter C: ");
	scanf("%f", &c);
	printf("Enter closest square num before C (stored as B): ");
	scanf("%f", &b);
	printf("Enter closest square num after C: (stored as A): ");
	scanf("%f", &a);
	printf("Enter square root of B: ");
	scanf("%f", &bsqrt);
	double sqrt = (1 / (a - b)) * (c - b) + bsqrt;
	printf("Square root of C is aproximately %f\n", sqrt);
}
