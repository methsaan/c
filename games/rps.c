#include<time.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

int main(int argc, char *argv) {
	srand(time(NULL));
	int x = (rand()%90)+1;
	char arr[3][20] = {"ROCK", "PAPER", "SCISSORS"};
	char *CMPchoice = arr[(x/6)%3];
	char USRchoice;
	printf("R, P, or S: ");
	scanf("%c", &USRchoice);
	char s = 'S';
	char p = 'P';
	char r = 'R';
	if ((USRchoice != s) && (USRchoice != r) && (USRchoice != p)){
		printf("You lose\n");
	}else if (USRchoice == *CMPchoice){
		printf("TIE\n");
	}else if (((USRchoice == s) && (*CMPchoice == r)) || ((USRchoice == r) && (*CMPchoice == p)) || ((USRchoice == p) && (*CMPchoice == s))){
		printf("Your choice: %c\n", USRchoice);
		printf("My choice: %c\n", *CMPchoice);
		printf("I win\n");
	}else {
		printf("Your choice: %c\n", USRchoice);
		printf("My choice: %c\n", *CMPchoice);
		printf("You win\n");
	}
}
