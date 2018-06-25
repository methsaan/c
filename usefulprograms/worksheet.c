#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

int main(int argc, char *argv){
	srand(time(NULL));
	for (int x = 0; x<10; x++) {
		printf("%d x %d\n", (rand()%100000)+1, (rand()%100000)+1);
		printf("%d \\ %d\n", (rand()%10000)+1, (rand()%1000)+1);
	}
	for (int x = 0; x<7; x++) {
		printf("Radius of circle is  %f. Find area and perimeter\n", (rand()%1000)/100);
	}
	for (int x = 0; x<5; x++){
		printf("Radius of cylinder is %f Height is %f. Find surface area and volume\n", (rand()%1000)/100, (rand()%10000/100));
	}
}
