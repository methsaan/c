#include<time.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {
	char usrrps[20];
	printf("Type rock, paper, or scissor: ");
	scanf("%s", usrrps);
	srand(time(NULL));
	char rps[3][20];
	strcpy(rps[0], "rock");
	strcpy(rps[1], "paper");
	strcpy(rps[2], "scissor");
	char randw[20] = rps[rand()%3];
	printf("%s", usrrps);
	printf("%s", randw);
}
