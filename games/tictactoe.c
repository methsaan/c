#include<time.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char *argv) {
	char usrrps[20];
	printf("Type rock, paper, or scissor: ");
	scanf("%s", usrrps);
	srand(time(NULL));
	char rps[3][20];
	strcpy(rps[0], "rock");
	strcpy(rps[1], "paper");
	strcpy(rps[2], "scissor");
	char randw[20];
	strcpy(randw, rps[(rand()%3)+1]);
	printf("What computer chose: %s what you chose: %s\n", randw, usrrps);
	if (strcmp(usrrps, randw) == 0){
		printf("Tie\n");
	}else{
		bool Rtop = ((strcmp(usrrps, "rock")) && (strcmp(randw, "paper")));
		bool Ptos = ((strcmp(usrrps, "paper")) && (strcmp(randw, "scissor")));
		bool Stor = ((strcmp(usrrps, "scissor")) && (strcmp(randw, "rock")));
		if ((Rtop) || (Ptos) || (Stor)){
			printf("I win.");
		}else{
			printf("You win.");
		}
	}
}
