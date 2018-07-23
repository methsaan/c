#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include<math.h>
#include<malloc.h>

float Round(float var){
	float value = (int)(var * 100 + 0.5);
	return (float)value / 100;
}
int main(int argc, char *argv){
	srand(time(NULL));
	int score = 0;
	int * pScore = &score;
	for(int a = 0; a < 2; a++){
		int x = (rand()%10000)+1;
		int y = (rand()%10000)+1;
		int inp;
		printf("What is %d x %d? ", x, y);
		scanf("%d", &inp);
		if (inp == x*y) {
			score++;
			pScore = &score;
		}else{
			pScore = &score;
		}
		double x2 = (rand()%1000)+1.0;
		double y2 = (rand()%100)+1.0;
		double inp2;
		printf("What is %f / %f? (2 decimal places) ", x2, y2);
		scanf("%f", inp2);
		printf("%f    %f", inp2, x2*y2);
		if (inp2 == x2/y2){
			score++;
			pScore = &score;
		}else {
			pScore = &score;
		}
	}
	printf("%d\n", *pScore);
	return 0;
}
