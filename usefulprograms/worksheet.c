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
		int x2 = (rand()%1000)+1;
		int y2 = (rand()%100)+1;
		double inp2;
		printf("What is %d / %d? (2 decimal places) ", x2, y2);
		scanf("%.2f", inp2);
		if (inp2 == Round(x2/y2)){
			score++;
			pScore = &score;
		}else {
			pScore = &score;
		}
	}
	printf("%d\n", *pScore);
	return 0;
}
