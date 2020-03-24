#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(int argc, char *argv){
	srand(time(0));
	int num;
	printf("Enter a number: ");
	scanf("%d", &num);
	int factors[num];
	int numOfFactors = 0;
	int cnt = 0;
	for (int x = 0; x < num; x++){
		if (((double)num)/((double)x) == (double)((int)((double)num/(double)x))){
			factors[cnt++] = num/x;
			numOfFactors++;
		}
	}
	factors[cnt] = 1;
	numOfFactors++;
	if (numOfFactors%2 == 0) {
		printf("Your number is not a perfect square\n");
	}else {
		printf("Your number is a perfect square\n");
	}
	printf("Number of factors: %d\n", numOfFactors);
	printf("Factors of %d: ", num);
	for (int x = 0; x < numOfFactors; x++) {
		printf("%d ", factors[x]);
	}
	printf("\n");
	return 0;
}
