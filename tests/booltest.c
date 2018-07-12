#include<stdio.h>
#include<stdbool.h>

int main(int argc, char *argv){
	bool x = 5 == 3;
	printf("x = %s\n", x ? "true" : "false");
	bool y = false;
	printf("y = %s\n", y ? "true" : "false");
}
