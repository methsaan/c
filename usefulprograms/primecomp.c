#include<stdio.h>

int main(int argc, char *argv){
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
	if (numOfFactors == 1){
		printf("Your number is neither prime nor composite\n");
	}else if (numOfFactors == 2){
		printf("Your number is prime\n");
	}else {
		printf("Your number is composite\n");
	}
	printf("Number of factors: %d\n", numOfFactors);
	printf("Factors of %d: ", num);
	for (int x = 0; x < numOfFactors; x++) {
		printf("%d ", factors[x]);
	}
	printf("\n");
	return 0;
}
