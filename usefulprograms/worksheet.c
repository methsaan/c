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
		system("clear");
		int x = (rand()%1000000)+1;
		int y = (rand()%1000000)+1;
		int inp;
		printf("What is %d x %d? ", x, y);
		scanf("%d", &inp);
		if (inp == x*y) {
			score++;
			pScore = &score;
		}else{
			pScore = &score;
		}
		system("clear");
		double xd = (rand()%1000)+1.0;
		double yd = (rand()%10)+1.0;
		float inp2;
		printf("What is %f / %f? (2 decimals) ", xd, yd);
		scanf("%f", inp2);
		if (inp2 == Round(xd/yd)){
			score++;
			pScore = &score;
		}else {
			pScore = &score;
		}
	}
	printf("%d\n", *pScore);
	return 0;
}
