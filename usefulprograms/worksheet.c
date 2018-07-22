#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include<math.h>
#include<malloc.h>

int main(int argc, char *argv){
	srand(time(NULL));
	int score = 1;
	int * pScore = &score;
	for(int a = 0; a < 5; a++){
		int x = (rand()%100)+1;
		int y = (rand()%100)+1;
		int inp = x+y;
		printf("What is %d x %d? ", x, y);
		scanf("%d", &inp);
		if (inp == x*y) {
			score++;
			pScore = &score;
		}else{
			pScore = &score;
		}
	}
	printf("%d\n", *pScore);
	return 0;
}
