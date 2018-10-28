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
		double ans = (double)randNumA / (double)randNumB;
		printf("Answer: %f\n", ans);
		printf("What is %d \u00F7 %d? ", randNumA, randNumB);
		scanf("%lf", &usrans);
		if (fabs(usrans-ans) < 0.000001){
			score++;
			pScore = &score;
		}else{
			pScore = &score;
		}
		double usrcylans;
		int height = (rand()%50)+1;
		int radius = (rand()%50)+1;
		double height2 = height;
		double radius2 = radius;
		double cylans = 2 * 3.141593 * radius2 * height2 + 2 * 3.141593 * radius2 * radius2;
		printf("Answer: %f\n", cylans);
		printf("Height: %d, radius: %d. Enter surface area:", height, radius);
		scanf("%lf", &usrcylans);
		if (fabs(usrcylans-cylans) < 10.000000){
			score++;
			pScore = &score;
		}else{
			pScore = &score;
		}
	}
	printf("%d\n", *pScore);
	return 0;
}
