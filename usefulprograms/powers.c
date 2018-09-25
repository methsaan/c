<<<<<<< HEAD
=======
#include <math.h>
>>>>>>> 104e758f98c7215026ff8634b234977d6ff041c8
#include <stdio.h>

int Pow(int num, int raised){
	int temp = num;
<<<<<<< HEAD
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
=======
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
>>>>>>> 104e758f98c7215026ff8634b234977d6ff041c8
}
