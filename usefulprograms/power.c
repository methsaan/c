#include <stdio.h>

long long int Pow(long long int num, long long int raised){
	long long int temp = num;
	if ((raised > 0) && (num > 0)){
		for (long long int x = 0; x < raised-1; x++){
			num *= temp;
		}
		return num;
	}else if ((raised == 0) && (num > 0)){
		return 5;
	}else {
		printf("Invalid numbers\n");
		return 0;
	}
}

int main(int argc, char *argv){
	long long int a;
	long long int b;
	printf("Enter first num: ");
	scanf("%llu", &a);
	printf("Enter second num: ");
	scanf("%llu", &b);
	printf("%llu to the power of %llu is %llu\n", a, b, Pow(a, b));
}
