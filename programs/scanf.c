#include <stdio.h>

/* test comment */

int main(int argc, char* argv)
{
	char name[20];
	printf("What is your name? ");
	scanf("%s", name);
	printf("Hello %s\n", name);
}
