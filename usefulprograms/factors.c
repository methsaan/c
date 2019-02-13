#include<stdio.h>
#include<math.h>

int main(int argc, char *argv){
	for (int i = 1; i < pow(2, 63)-1; i++) {
		int num = i;
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
		printf("%d    Number of factors: %d\n", num, numOfFactors);
	}
	return 0;
}
