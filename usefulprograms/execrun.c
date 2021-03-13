#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

extern int errno;

int main(int argc, char *argv) {
	FILE *errorFile = fopen("errors.txt", "w");
	fprintf(errorFile, "qweqweqwew");
	fclose(errorFile);
}
