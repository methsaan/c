#include <stdio.h>

int Pow(int num, int raised){
	int temp = num;
	// zero and negative numbers; to be continued
	for (int x = 0; x < raised-1; x++){
		num *= temp;
	}
	return num;
}
int main(int argc, char* argv){
	int a;
	int b;
	printf("Enter number: ");
	scanf("%d", &a);
	printf("Enter power: ");
	scanf("%d", &b);
	printf("%d to the power of %d is %d\n", a, b, Pow(a, b));
}
