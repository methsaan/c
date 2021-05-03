#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

extern int errno;

int main(int argc, char *argv) {
	printf("hahooooooo waaaaa hoo poopidiot\n");
	FILE *fp = fopen("errors.txt", "w");
	fprintf(fp, "ERROR:\n");
	fclose(fp);
	system("gcc execfile.c 2>> errors.txt");
}
