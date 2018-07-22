#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include<math.h>
#include<malloc.h>

int main(int argc, char *argv){
	srand(time(NULL));
	int x = (rand()%100)+1;
	int y = (rand()%100)+1;
	int inp = x+y;
	printf("What is %d + %d? ", x, y);
	scanf("%d", &inp);
	if (inp == x+y){
		printf("Correct\n");
	}else{
		printf("wrong %d", x+y);
	}
	return 0;
}
