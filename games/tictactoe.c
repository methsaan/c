#include<time.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {
	int randnum;
	char usrrps[1];
	printf("Rock, paper, or scissor (r, p, s): ");
	scanf("%s", usrrps);
	srand(time(NULL));
	char rps[3][2] = {"rr","pp","ss"};
	randnum = rand()%3;
	if (strcmp(usrrps, rps) == 0){
		printf("TIE!!\n");
	}else if (strcmp(usrrps, "p") == 0) {
		if (strcmp(rps, "ss") == 0) {
			printf("I WIN!!\n");
		}
	}else if (strcmp(usrrps, "s") == 0){
		if (strcmp(rps, "rr") == 0) {
			printf("I WIN!!\n");
		}
	}else if (strcmp(usrrps, "r") == 0){
		if (strcmp(rps, "pp") == 0){
			printf("I WIN!!\n");
		}
	}else{
		printf("YOU WIN!!\n");
	}
}
