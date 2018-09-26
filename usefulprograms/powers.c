#include <math.h>
#include <stdio.h>

unsigned long long int Pow(unsigned long long int num, unsigned long long int raised){
	if ((num > 0) && (raised > 0)){
		unsigned long long int temp = num;
		for (unsigned long long int x = 0; x < raised-1; x++){
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
	unsigned long long int x = 0;
	unsigned long long int y = 1;
	while ((x < 63) && (y < 64)){
		if (y < 19){ 
			if (x != 0){
				printf("2 to the power of %llu is %llu\t\t\t\t2 to the power of %llu is %llu\n", x, Pow(2, x), y, Pow(2, y));
			}else {
				printf("2 to the power of 0 is -1  \t\t\t\t  2 to the power of %llu is %llu\n", y, Pow(2, y));
			}
		}else if ((y >= 19) && (y < 45)){
			printf("2 to the power of %llu is %llu\t\t\t2 to the power of %llu is %llu\n", x, Pow(2, x), y, Pow(2, y));
		}else {
			printf("2 to the power of %llu is %llu\t\t2 to the power of %llu is %llu\n", x, Pow(2, x), y, Pow(2, y));
		}
		x += 2;
		y += 2;
	}
	return 0;


}
