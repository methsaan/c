#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

int main(int argc, char *argv){
	srand(time(NULL));
	while (true) {
		printf("%d\n", (rand()%1000)+1);
	}
}
