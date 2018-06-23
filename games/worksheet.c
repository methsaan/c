#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

int main(int argc, char *argv){
	srand(time(NULL));
	for (int x = 0; x>10; x++) {
		printf("%d X %d\n", (rand()%100000)+1, (rand()%100000)+1);
	}
}
