#include<stdio.h>
#include<math.h>
#include<stdlib.h>

double formulaSqrt(int A, int B, int C, int Bsqrt){
	return (1.000000 / (A - B)) * (C - B) + Bsqrt;
}
int main(int argc, char *argv){
	int c;
	int a;
	int b;
        int bsqrt;
	printf("Enter C: ");
	scanf("%d", &c);
	printf("Enter closest square num before C: (stored as B) ");
	scanf("%d", &b);
	printf("Enter closest square num after C: (stored as A) ");
	scanf("%d", &a);
	printf("Square root according to formula: %f\n", formulaSqrt(a, b, c, (int)sqrt(b)));
	printf("Square root according to sqrt(): %f\n", sqrt(c));
	printf("Accuracy: %f\n", sqrt(c)-formulaSqrt(a, b, c,(int)sqrt(b)));
}
