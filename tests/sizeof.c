#include<stdio.h>
#include<unistd.h>

int arrsize(double * arr){
	return sizeof(arr)/sizeof(*arr);
}

int main(int argc, char * argv){
	double x[] = {12.13, 2356.125, 123.21512, 2133.2512, 1234.5, 264.12, 1242.5};
	printf("%d\n", arrsize(x));
}
