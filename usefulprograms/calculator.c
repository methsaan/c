#include <stdio.h>
#include <math.h>

int main(int argc, char* argv)
{
	int x;
	int y;
	char op[1];
	printf("Enter operator:(++, --, xx, //) ");
	scanf("%s", op);
	printf("Enter x: ");
	scanf("%d", &x);
	printf("Enter y: ");
	scanf("%d", &y);
	if (op == "++"){
		printf("%d\n", x+y);
	}
	if (op == "--"){
		printf("%d\n", x-y);
	}
	if (op == "xx"){
		printf("%d\n", x*y);
	}
	if (op == "//"){
		printf("%d\n", x/y);
	}
}
