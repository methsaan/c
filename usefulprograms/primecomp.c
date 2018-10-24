#include<stdio.h>

int main(int argc, char *argv){
	int num;
	printf("Enter a number: ");
	scanf("%d", &num);
	int numOfFactors = 0;
	for (int x = 0; x < num; x++){
		if (((double)num)/((double)x) == (double)((int)((double)num/(double)x))){
			numOfFactors++;
		}
	}
	if (numOfFactors == 0){
		printf("Your number is neither prime nor composite\n");
	}else if (numOfFactors == 1){
		printf("Your number is prime\n");
	}else {
		printf("Your number is composite\n");
	}
	printf("Number of factors: %d\n", (numOfFactors*2)-1);
	return 0;
}
