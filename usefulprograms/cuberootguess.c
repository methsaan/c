#include <stdio.h>
#include <math.h>

int main(int argc, char *argv){
	double cube;
	double cuberoot;
	int numberOfGuesses = 0;
	printf("Enter a number: ");
	scanf("%lf", &cube);
	double high = cube, low = 0.0;
	while (1) {
		cuberoot = low + ((high - low) / 2);
		if (cuberoot*cuberoot*cuberoot < cube) {
			low = cuberoot;
		}else {
			high = cuberoot;
		}
		if (fabs(cuberoot*cuberoot*cuberoot-cube) < 0.000001) {
			break;
		}
		numberOfGuesses++;
		printf("%d \t %f\n", numberOfGuesses, cuberoot);
		getchar();
		getchar();
	}
	printf("%d \t %f\n", ++numberOfGuesses,  cuberoot);
}
