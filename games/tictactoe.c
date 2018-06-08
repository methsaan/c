#include<time.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {
	int randmax;
	int rps2;
	char rps[1];
	printf("Rock, paper, or scissor (r, p, s): ");
	scanf("%s", rps);
	printf("%s\n", rps);
	srand(time(NULL));
	randmax = (100*rand())/RAND_MAX;
	printf("%d %d\n", randmax, rand());
}
