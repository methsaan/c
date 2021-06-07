#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int errorLine() {
	FILE *fp = fopen("errors.txt", "w");
	fprintf(fp, "ERROR:\n");
	fclose(fp);
	system("gcc execfile.c 2>> errors.txt");
	char buff[50];
	FILE *fp2 = fopen("errors.txt", "r");
	fscanf(fp2, "%s", buff);
	// return location of errors
}
