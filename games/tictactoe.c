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
	char rps[3][1] = {"r","p","s"};
	randnum = rand()%3;
	if (strcmp(usrrps, rps) == 0){
		printf("TIE!!\n");
	}else if ((strcmp(usrrps, 'p') == 0) && (strcmp(rps, "s") == 0)){
		printf("I WIN!!\n");
	}else if ((strcmp(usrrps, 's') == 0) && (strcmp(rps, "r") == 0)) {
		printf("I WIN!!\n");
	}else if ((strcmp(usrrps, 'r') == 0) && (strcmp(rps, "p") == 0)){
		printf("I WIN!!\n");
	}else{
		printf("YOU WIN!!\n");
	}
}
