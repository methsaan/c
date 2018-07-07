#include<stdio.h>

int main(int argc, char * argv){
	int x[] = {12, 2356, 123, 21353, 1234, 264};
	int y = sizeof(x)/sizeof(x[0]);
	printf("%d", y);
}
