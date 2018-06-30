#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

int main(int argc, char *argv){
	srand(time(NULL));
	double ans;
	int ans2;
	int score;
	for (int x = 0; x<6; x++) {
		int xmul = (rand()%10000)+1;
		int ymul = (rand()%10000)+1;
		printf("%d x %d ", xmul, ymul);
		scanf("%d", &ans2);
		if (xmul*ymul == ans2){
			score++;
		}
		int xdiv = (rand()%10000)+1;
		int ydiv = (rand()%1000)+1;
		printf("%d / %d ", xdiv, ydiv);
		scanf("%f", &ans);
		if (xdiv/ydiv == ans){
			score++;
		}
	}
	for (int x = 0; x<5; x++) {
		double rad = (rand()%1000)/100.00;
		printf("Radius of circle is  %f\n", rad);
		printf("Enter circumference: ");
		scanf("%f", &ans);
		if (2*rad*3.14 == ans){
			score++;
		}
		printf("Enter area: ");
		scanf("%f", &ans);
		if (3.14*rad*rad == ans){
			score++;
		}
	}
	for (int x = 0; x<4; x++){
		double rad = (rand()%1000)/100.00;
		double h = (rand()%10000)/100.00;
		printf("Radius of cylinder is %f Height is %f.\n", rad, h);
		printf("Enter surface area: ");
		scanf("%f", &ans);
		if (((2*rad*3.14)*h)+((3.14*rad*rad)*2) == ans){
			score++;
		}
		printf("Enter volume: ");
		scanf("%f", &ans);
		if ((3.14*rad*rad)*h == ans){
			score++;
		}
	}
	printf("%d\n", score);
}
