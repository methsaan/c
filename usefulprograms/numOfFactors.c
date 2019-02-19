#include<stdio.h>
#include "numOfFactors.h"

int main(int argc, char *argv){
	int numberOfFactors[COUNT];
	for (int i = 0; i < COUNT; i++) {
		int num = i;
		int factors[(int)num];
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
		printf("%d ::: ", num);
		for (int x = 0; x < numOfFactors; x++) {
			printf("%d ", factors[x]);
		}
		printf(" \t\t\t (%d)\n", numOfFactors);
		numberOfFactors[i] = numOfFactors;
		for (long long int a = 0; a < SLEEP; a++) {
			;
		}
	}
	int temp;
	int numbers[COUNT];
	for (int x = 0; x < COUNT; x++) {
		numbers[x] = x;
	}
	for (int x = 0; x < COUNT; x++) {
		for (int y = x+1; y < COUNT; y++) {
			if (numberOfFactors[x] > numberOfFactors[y]) {
				temp = numberOfFactors[x];
				numberOfFactors[x] = numberOfFactors[y];
				numberOfFactors[y] = temp;
				temp = numbers[x];
				numbers[x] = numbers[y];
				numbers[y] = temp;
			}
		}
	}
	for (int x = 0; x < COUNT; x++) {
		printf("%d \t\t %d\n", numberOfFactors[x], numbers[x]);
	}
	return 0;
}
