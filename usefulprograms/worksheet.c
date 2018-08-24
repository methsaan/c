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
	for(int a = 0; a < 6; a++){
		int x = (rand()%10000)+1;
		int y = (rand()%10000)+1;
		int inp;
		printf("What is %d x %d? ", x, y);
		scanf("%d", &inp);
		if (inp == x*y) {
			score++;
			pScore = &score;
			printf("Your answer: %d\ncorrect answer: %d\n", inp, x*y);
		}else{
			printf("Your answer: %d\ncorrect answer: %d\n", inp, x*y);
			pScore = &score;
		}
		double a = (rand()%100)+1.00;
		double b = (rand()%100)+1.00;
		double ans = a/b;
		double USRans;
		printf("What is %f / %f? ", a, b);
		scanf("%f", &USRans);
		printf("Correct answer: %f\n", ans);
		printf("Your answer: %f\n", USRans);
	}
	printf("%d\n", *pScore);
	return 0;
}
