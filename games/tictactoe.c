#include<time.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {
	int randnum;
	char rps[1];
	printf("Rock, paper, or scissor (r, p, s): ");
	scanf("%s", rps);
	printf("%s\n", rps);
	srand(time(NULL));
	char rps2[3] = {'r','p','s'};
	randnum = rand()%3;
	printf("%c\n", rps2[randnum]);
}
