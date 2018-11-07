#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void wait(unsigned timeout){
	timeout += clock();
	while (clock() < timeout)
		continue;
}
int main(int argc, char*argv){
	wait();
	printf("HO\n");
	wait();
	printf("HO!\n");
	wait();
	printf("HO!\n");
}
