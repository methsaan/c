#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

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
	int sf;
	int ss;
	sf = s;
	while (sf >= 10){
		sf = sf / 10;
	}
	ss = s % 10;
	int prod1 = f * ss;
	int prod2 = f * sf;
	if (((prod1>99)&&(prod1<1000)) && ((prod2>99)&&(prod2<1000))){
		printf("   %d\n", prod1);
		printf("  %d\n", prod2);
		printf("_________\n");
		printf("  %d\n", prod1+prod2*10);
	}else if (((prod1>9)&&(prod1<100)) && ((prod2>9)&&(prod2<100))){
		printf("    %d\n", prod1);
		printf("   %d\n", prod2);
		printf("_________\n");
		printf("   %d\n", prod1+prod2*10);
	}else if (((prod1>99)&&(prod1<1000)) && ((prod2>9)&&(prod2<100))){
		printf("    %d\n", prod1);
		printf("    %d\n", prod2);
		printf("_________\n");
		printf("    %d\n", prod1+prod2*10);
	}else if (((prod1>9)&&(prod1<100)) && ((prod2>99)&&(prod2<1000))){
		printf("     %d\n", prod1);
		printf("   %d\n", prod2);
		printf("_________\n");
		printf("   %d\n", prod1+prod2*10);
	}
}
