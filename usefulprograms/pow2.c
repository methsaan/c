#include <math.h>
#include <stdio.h>

void bla(int *num, int times){
	int temp = *num;
	for (int x = 0; x < times; x++){
		*num += temp;
	}
}
int Pow(int x, int y){
	int temp = x;
	for (int a = 0; a < y-1; a++){
		bla(&x, y);
	}
	return x;
}


int main(int argc, char *argv){
	printf("%d\n", Pow(2, 4));
}
