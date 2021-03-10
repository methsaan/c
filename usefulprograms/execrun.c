#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv) {
	// program works so far
	// store compilation results in errors.txt
	//
	FILE *fpipe;
	char *command = "gcc execfile.c";
	char c = 0;
	if (0 == (fpipe = (FILE*)popen(command, "r"))) {
		perror("popen() failed.");
		exit(EXIT_FAILURE);
	}
	while (fread(&c, sizeof(c), 1, fpipe)) {
		printf("%c", c);
	}
}
