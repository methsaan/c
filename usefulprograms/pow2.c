#include <stdio.h>

int Pow(int num, int raised){
	int temp = num;
	if (raised < 0){
		printf("ERROR: cannot raise to a negative number\n");
		return '#';
	}
	if (num < 0){
		printf("ERROR: cannot raise negative number\n");
		return '$';
	}
	if (raised == 0){
		return -1;
	}else {
		for (int x = 0; x < raised-1; x++){
			num *= temp;
		}
		return num;
	}
}

int main(int argc, char *argv){
	int a;
	int b;
	printf("Enter first num: ");
	scanf("%d", &a);
	printf("Enter second num: ");
	scanf("%d", &b);
	printf("%d to the power of %d is %d\n", a, b, Pow(a, b));
}
