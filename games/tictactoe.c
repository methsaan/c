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
	if ((twelveRand == 1) || (twelveRand == 3) || (twelveRand == 8) || (twelveRand == 12)) {
		strcpy(rps[0], "rock");
	}
	else if ((twelveRand == 9) || (twelveRand == 5) || (twelveRand == 4) || (twelveRand == 11)){
		strcpy(rps[1], "paper");
	}
	else {
		strcpy(rps[2], "scissor");
	}
	char randw[20];
	printf("%s\n", rps[rand()%3]);
	randw = rps[rand()%3];
	printf("%s\n", randw);
	printf("Computer choice: %s.  Your choice: %s\n", randw, usrrps);
	if (strcmp(usrrps, randw) == 0){
		printf("TIE\n");
	}else{
		if (((strcmp(usrrps, "rock") == 0) && (strcmp(randw, "paper") == 0)) || ((strcmp(usrrps, "rock") == 0) && (strcmp(randw, "paper") == 0)) ||  ((strcmp(usrrps, "rock") == 0) && (strcmp(randw, "paper") == 0))) {
			printf("I win.\n");
		}else{
			printf("You win.\n");
		}
	}
}
