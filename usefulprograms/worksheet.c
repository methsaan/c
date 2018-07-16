#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include<math.h>

int main(int argc, char *argv){
	srand(time(NULL));
	double ans;
	int ans2;
	int score;
	int xmul;
	int ymul;
	double xdiv;
	double ydiv;
	for (int x = 0; x<1; x++) {
		int xmul = (rand()%1000)+1;
		int ymul = (rand()%1000)+1;
		printf("%d x %d: ", xmul, ymul);
		scanf("%d", &ans2);
		if (xmul*ymul == ans2){
			score++;
		}
		double dec = (rand()%99)/100.00;
		double dec2 = (rand()%99)/100.00;
		double xdiv = (double)(rand()%10000)+1+dec;
		double ydiv = (double)(rand()%1000)+1+dec2;
		printf("%f / %f (2 decimals only): ", xdiv, ydiv); 
		scanf("%.2f", ans);
		if (xdiv/ydiv == ans){
			score++;
		}
	}
	printf("score: %d\n", &score);
	int answermul = xmul * ymul;
	int answerdiv = xdiv * ydiv;
	printf("%d x %d = %d\n%.2f / %.2f = %.2f", &xmul, &ymul, &answermul, xdiv, ydiv, answerdiv);
}
