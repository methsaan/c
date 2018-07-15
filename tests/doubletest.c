#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(int argc, char *argv){
	srand(time(NULL));
	double c = (rand()%10000)/100.00;
	printf("%f\n", c);
}
