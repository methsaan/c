#include<stdio.h>

int main(int argc, char* argv){
	int x;
	scanf("My number is %d", &x);
	switch(x){
		case 1:
			printf("Your number is 1\n");
			break;
		case 2:
			printf("Your number is 2\n");
			break;
		case 3:
			printf("Your number is 3\n");
			break;
		case 4:
			printf("Your number is 4\n");
			break;
		case 5:
			printf("Your number is 5\n");
			break;
		default:
			printf("Your number is greater than 5\n");
	}
	return 0;
}
