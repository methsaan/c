#include<stdio.h>
#include<stdlib.h>
#include<math.h>

char * toArray(int number){
	int n = log10(number) + 1;
	int i;
	char *numberArray = calloc(n, sizeof(char));
	for (i = 0; i < n; ++i, number /= 10){
		numberArray[i] = number % 10;
	}
	return numberArray;
}
int strtoi(char * str){
	int num[sizeof(str)/sizeof(*str)];
	int num2;
	for (int x = 0; x < sizeof(str)/sizeof(*str); x++){
		num[x] = str[x] - '0';
	}
}
int main(int argc, char *argv){
	int f;
	int s;
	printf("Enter first num (2 digits): ");
	scanf("%d", &f);
	printf("Enter second num (2 digits): ");
	scanf("%d", &s);
	printf("    %d\n", f);
	printf("    %d\n", s);
	printf("   ______\n");
	char *strf = toArray(f);
	int prod1 = strtoi(strf[0])*f;
	int prod2 = strtoi(strf[1])*f;
	printf("   %d\n", prod1);
	printf("  %d\n", prod2);
	printf("_________\n");
	printf("%d", prod1+prod2);
}
