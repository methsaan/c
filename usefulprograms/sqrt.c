#include<stdio.h>

int main(int argc, char *argv){
	double c;
	int a;
	int b;
	int bsqrt;
	printf("Enter C: ");
	scanf("%f", &c);
	printf("Enter closest square num before C (stored as B): ");
	scanf("%d", &b);
	printf("Enter closest square num after C: (stored as A): ");
	scanf("%d", &a);
	printf("Enter square root of B: ");
	scanf("%d", &bsqrt);
	double sqrt = (1 / (a - b)) * (c - b) + bsqrt;
	printf("Square root of C is aproximately %f\n", &sqrt);
}
