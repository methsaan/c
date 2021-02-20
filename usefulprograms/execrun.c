#include <stdio.h>

int main(int argc, char *argv) {
	FILE *fp;
	int status;
	
	fp = popen("gcc execfile.c -lm -o a.out");
	if (fp == NULL) {
		printf("Error\n");
		// ...
	}else {
		system("./a.out");
	}
}
