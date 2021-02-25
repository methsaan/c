#include <stdio.h>
#include <stdlib.h>
#include <linux/limits.h>

int main(int argc, char *argv) {
	// fix looping issue
	FILE *fp;
	int status;
	char path[PATH_MAX];
	fp = popen("gcc execfile.c -lm -o a.out", "r");
	if (fp == NULL) {
		printf("fp is NULL\n");
	}
	while (fgets(path, PATH_MAX, fp) != NULL) {
		printf("%s", path);
	}
	status = pclose(fp);
	if (status == -1) {
		printf("Error\n");
		// ...
	}else {
		system("./a.out");
	}
}
