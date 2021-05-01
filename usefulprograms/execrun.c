#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

extern int errno;

int main(int argc, char *argv) {
	FILE *fp = fopen("gcc execfile.c", "w");
	fclose(fp);
	system("gcc execfile.c 2>> errors.txt");
}
