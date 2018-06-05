#include<time.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {
	char rps[1];
	printf("Rock, paper, or scissor (r, p, s): ");
	scanf("%s", rps);
	int r = rand() % 3;
	printf("%d\n", r);
}
