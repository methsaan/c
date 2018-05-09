#include <stdio.h>

int main(int argc, char* argv)
{
	char name[20];
	printf("What is your name? ");
	scanf("%s", name);
	printf("Hello %s\n", name);
}
