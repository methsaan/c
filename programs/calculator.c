#include <stdio.h>

int main(int argc, char* argv)
{
	char oper[5];
	printf("Operation ([a]dd/[s]ubstract/[m]ultiply/[d]ivide/[m]odulus) ? ");
	scanf("%s", oper);
    printf("OK, we are going to %s things\n", oper);
}
