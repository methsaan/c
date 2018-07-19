#include<stdio.h>
#include<stdlib.h>
#include<math.h>

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
	char strf[2];
	strcpy(strf[1], f);
	int a = (int)strf[1];
	int b = (int)strf[0];
	int prod1 = (int)(a)*f;
	int prod2 = (int)(b)*f;
	printf("   %c\n", prod1);
	printf("  %c\n", prod2);
	printf("_________\n");
	printf("%d\n", prod1+prod2);
}       
