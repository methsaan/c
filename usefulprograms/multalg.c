#include<stdio.h>

int main(int argc, char *argv){
	int f;
	int s;
	char strf[5];
	char strs[5];
	printf("Enter first num (2 digits): ");
	scanf("%d", &f);
	printf("Enter second num (2 digits): ");
	scanf("%d", &s);
	printf("    %d\n", f);
	printf("    %d\n", s);
	printf("   ______\n");
	strf = itoa(f, strf, 10);
	int prod1 = atoi(strs[1])*f;
	int prod2 = atoi(strs[0])*f;
	printf("   %d\n", prod1);
	printf("  %d\n", prod2);
	printf("_________\n");
	printf("%d", prod1+prod2);
}
