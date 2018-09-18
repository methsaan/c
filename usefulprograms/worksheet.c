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
		printf("%d\n", x*y);
		printf("What is %d \u00D7 %d? ", x, y);
		scanf("%d", &inp);
		if (inp == x*y) {
			score++;
			pScore = &score;
		}else{
			pScore = &score;
		}
		double usrans;
		int randNumA = (rand()%100)+1;
		int randNumB = (rand()%100)+1;
		double doubleNumA = randNumA;
		double doubleNumB = randNumB;
		double ans = doubleNumA / doubleNumB;
		printf("%f\n", ans);
		printf("What is %f \u00F7 %f? ", doubleNumA, doubleNumB);
		scanf("%lf", &usrans);
		if (fabs(usrans-ans) < 0.000001){
			score++;
			pScore = &score;
		}else{
			pScore = &score;
		}
	}
	printf("%d\n", *pScore);
	return 0;
}
