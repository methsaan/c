#include <math.h>
#include <stdio.h>

int Pow(int num, int raised){
	int temp = num;
	// zero and negative numbers; to be continued
	for (int x = 0; x < raised-1; x++){
		num *= temp;
	}
	return num;
}

int main(int argc, char *argv){
	int a;
	int b;
	printf("Enter first number: ");
	scanf("%d", &a);
	printf("Enter second number: ");
	scanf("%d", &b);
	printf("%d\n", Pow(a, b));
	return 0;
}
