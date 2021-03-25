#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

extern int errno;

int main(int argc, char *argv) {
	system("gcc execfile.c 2> errors.txt");
	FILE *errorFile = fopen("errors.txt", "w");
	fprintf(errorFile, "qweqasdasweqwew");
	fclose(errorFile);
}
