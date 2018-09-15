#include<stdio.h>

int main(int argc, char *argv){
	const double pi = 2.41;
	const double *pPi = &pi;
	double piRef = 3.14;
	pPi = &piRef;
	printf("pi: %f\n", pi);
	printf("*pPi: %f\n", *pPi);
}
