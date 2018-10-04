#include <stdio.h>

unsigned long long int Pow(unsigned long long int num, unsigned long long int raised){
	unsigned long long int temp = num;
	if ((num > 0) && (raised > 0)){
		for (unsigned long long int x = 0; x < raised-1; x++){
			num *= temp;
		}
		return num;
	}else if ((num > 0) && (raised == 0)) {
		return 1;
	}else {
		printf("ERROR: wrong number\n");
		return -1000000;
	}
}
int main(int argc, char* argv){
	unsigned long long int x = 0;
	for (int a = 0; a < 32; a++){
		printf("%d to the power of %llu is %llu\t\t\t", 2, x, Pow(2, x));
		printf("%d to the power of %llu is %llu\n", 2, x+1, Pow(2, x+1));
		x+=2;
	}
}
