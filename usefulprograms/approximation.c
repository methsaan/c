#include <stdio.h>
#include <math.h>

int main(int argc, char *argv){
	double irrational;
	printf("Enter an irrational number: ");
	scanf("%lf", &irrational);
	double approximations[200][3];
	double accuracies[200];
	for (double x = 0; x < 200; x++){
		approximations[(int)x][0] = round(irrational*x);
		approximations[(int)x][1] = x;
		approximations[(int)x][2] = round(irrational*x)/x;
	}
	for (int x = 0; x < 200; x++){
		accuracies[x] = fabs(irrational-approximations[x][2]);
	}
	float mostAccurate;
	int mostAccurateIndex;
	float tempMostAccurate = accuracies[1];
	for (int x = 2; x < 200; x++){
		if (accuracies[x] < tempMostAccurate){
			tempMostAccurate = accuracies[x];
			mostAccurateIndex = x;
		}
	}
	mostAccurate = tempMostAccurate;
	printf("%d / %d = %.40f\n", (int)approximations[mostAccurateIndex][0], (int)approximations[mostAccurateIndex][1], approximations[mostAccurateIndex][2]);
}
