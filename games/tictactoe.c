#include<time.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {
	int randnum;
	const char usrrps[20];
	printf("Type rock, paper, or scissor: ");
	scanf("%s", &usrrps);
	srand(time(NULL));
	const char *rps[3][2] = {"rr","pp","ss"};
	randnum = rand()%3;
	if (strcmp(usrrps, rps) == 0){
		printf("TIE!!\n");
	}else if (strcmp(usrrps, "paper") == 0) {
		if (strcmp(rps, "ss") == 0) {
			printf("I WIN!!\n");
		}
	}else if (strcmp(usrrps, "scissor") == 0){
		if (strcmp(rps, "rr") == 0) {
			printf("I WIN!!\n");
		}
	}else if (strcmp(usrrps, "rock") == 0){
		if (strcmp(rps, "pp") == 0){
			printf("I WIN!!\n");
		}
	}else{
		printf("YOU WIN!!\n");
	}
}
