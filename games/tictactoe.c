#include<time.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {
	char randw;
	char usrrps[20];
	printf("Type rock, paper, or scissor: ");
	scanf("%s", usrrps);
	srand(time(NULL));
	char rps[3][20] = {"rock","paper","scissor"};
	randw = rps[rand()%3];
	printf("%s", randw);
	/*if (usrrps == randw){
		printf("TIE!!\n");
	}else if (usrrps == "paper") {
		if (randw == "scissor") {
			printf("I WIN!!\n");
		}
	}else if (usrrps == "scissor"){
		if (randw == "rock") {
			printf("I WIN!!\n");
		}
	}else if (usrrps == "rock"){
		if (randw == "paper"){
			printf("I WIN!!\n");
		}
	}else{
		printf("YOU WIN!!\n");
	}*/
}
