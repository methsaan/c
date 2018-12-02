#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv){
	char a[10];
	printf("Enter a string: ");
	scanf("%s", a);
	int x = atoi(a);
	printf("atoi(\"%s\") = %d\n", a, x);
	int y;
	printf("Enter an integer: ");
	scanf("%d", &y);
	char b[10];
	snprintf(b, 10, "%d", y);
	printf("itoa(%d) = \"%s\"\n", y, b);
	double z;
	printf("Enter an float: ");
	scanf("%lf", &z);
	char c[10];
	snprintf(b, 10, "%f", z);
	printf("ftoi(%f) = \"%s\"\n", z, c);
}
