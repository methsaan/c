#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 128

int main(int argc, char *argv) {
	FILE *errorFile = fopen("errors.txt", "w");
	fprintf(errorFile, "qweqweqwew");
	fclose(errorFile);

	char *cmd = "dqmpog";

	char buf[BUFSIZE];
	FILE *fp;

	if ((fp = popen(cmd, "r")) == NULL) {
		return -1;
	}

	while (fgets(buf, BUFSIZE, fp) != NULL) {
		printf("%s", buf);
	}

	if (pclose(fp)) {
		// error
		printf("Command not found or exited with error status\n");
		return -1;
	}
}
