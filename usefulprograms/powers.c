#include <math.h>
#include <stdio.h>

signed long long int Pow(signed long long int num, signed long long int raised){
	if ((num > 0) && (raised > 0)){
		signed long long int temp = num;
		for (signed long long int x = 0; x < raised-1; x++){
			num *= temp;
		}
		return num;
	}else if ((raised == 0) && (num > 0)){
		return -1;
	}else {
		printf("ERROR: Invalid numbers\n");
		return 0;
	}
}

int main(int argc, char *argv){
	for (signed long long int x = 0; x < 32; x++){
		printf("2 to the power of %d is %lld\n", x, Pow(2, x));
	}
	return 0;
}
