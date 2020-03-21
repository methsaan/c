#include<stdio.h>
#include<math.h>

int main(int argc, char *argv){
	for (unsigned int i = 1; i < pow(2, 11)-1; i++) {
		unsigned int num = i;
		unsigned int factors[num];
		unsigned int numOfFactors = 0;
		unsigned int cnt = 0;
		for (unsigned int x = 0; x < num; x++){
			if (((double)num)/((double)x) == (double)((unsigned int)((double)num/(double)x))){
				factors[cnt++] = num/x;
				numOfFactors++;
			}
		}
		factors[cnt] = 1;
		numOfFactors++;
		printf("%u    Number of factors: %u     Number-factor count ratio: %f \n", num, numOfFactors, (double)num/numOfFactors);
	}
	return 0;
}
