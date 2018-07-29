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
		long int inp;
		printf("What is %d x %d? ", x, y);
		scanf("%ld", &inp);
		if (inp == x*y) {
			score++;
			pScore = &score;
		}else{
			printf("Your answer: %ld\ncorrect answer: %ld\n", inp, x*y);
			pScore = &score;
		}
		//system("clear");
		//float xd = (rand()%1000)+1.0;
		//float yd = (rand()%10)+1.0;
		//float inp2;
		//printf("What is %g / %g? (2 decimals) ", xd, yd);
		//scanf("%f", inp2);
		//printf("%f\n", Round(xd/yd));
	}
	printf("%d\n", *pScore);
	return 0;
}
