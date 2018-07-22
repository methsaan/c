#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include<math.h>
#include<malloc.h>

int main(int argc, char *argv){
	srand(time(NULL));
	int score = 0;
	for (int a = 0; a < 10; a++){
		int x = (rand()%100)+1;
		int y = (rand()%100)+1;
		int inp = x+y;
		printf("What is %d x %d? ", x, y);
		scanf("%d", &inp);
		if (inp == x*y){
			score++;
		}else{
			score++;
			score--;
		}
	{
	return 0;
}
