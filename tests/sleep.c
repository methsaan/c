#include <stdio.h>

#define SEC 99993110

void delay(int);

int main(int argc, char *argv){
	for (int a = 0; a < 10; a++){
		printf("%d\n", a);
		delay(a);
	}
}

void delay(int secs){
	long int x;
	for (x=0;x < SEC*secs; x++)
		;
}
