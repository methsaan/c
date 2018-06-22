#include<time.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

int main(int argc, char *argv) {
	char usrrps[20];
	printf("Type rock, paper, or scissor: ");
	scanf("%s", usrrps);
	srand(time(NULL));
	int twelveRand = (rand()%12)+1;
	char rps[3][20];
	if (twelveRand <= 4) {
		strcpy(rps[0], "rock");
	}
	else if ((twelveRand <= 8) && (twelveRand >= 5)){
		strcpy(rps[1], "paper");
	}
	else {
		strcpy(rps[2], "scissor");
	}
	char randw[20];
	strcpy(randw, rps[(rand()%3)+1]);
	printf("What computer chose: %s what you chose: %s\n", randw, usrrps);
	if (strcmp(usrrps, randw) == 0){
		printf("TIE\n");
	}else{
		bool Rtop = (strcmp(usrrps, "rock")) && (strcmp(randw, "paper"));
		bool Ptos = (strcmp(usrrps, "paper")) && (strcmp(randw, "scissor"));
		bool Stor = (strcmp(usrrps, "scissor")) && (strcmp(randw, "rock"));
		if (((strcmp(usrrps, "rock")) && (strcmp(randw, "paper"))) || ((strcmp(usrrps, "rock")) && (strcmp(randw, "paper"))) ||  ((strcmp(usrrps, "rock")) && (strcmp(randw, "paper")))) {
			printf("I win.\n");
		}else if ((strcmp(usrrps, "rock") != 0) || (strcmp(usrrps, "scissor") != 0) || (strcmp(usrrps, "paper") != 0) || (strcmp(randw, "rock") != 0) || (strcmp(randw, "scissor") != 0) || (strcmp(randw, "scissor") != 0)) {
			printf("DRAW\n");
		}else{
			printf("You win.\n");
		}
	}
}
