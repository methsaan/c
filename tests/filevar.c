#include <stdio.h>

int main(int argc, char *argv){
	FILE file = *fopen("doubletest.c", "r");
	printf("%d\n", sizeof(file));
}
