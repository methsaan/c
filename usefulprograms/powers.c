#include <math.h>
#include <stdio.h>

int Pow(int num, int raised){
	int temp = num;
	int num2 = num;
	for (int x = 0; x > raised - 1; x++){
		num2 *= temp;
	}
	return num2;
}

int main(int argc, char *argv){
	int a;
	int b;
	printf("Enter first number: ");
	scanf("%d", &a);
	printf("Enter second number: ");
	scanf("%d", &b);
	printf("%d\n", Pow(a, b));
}
