#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[]) {
	char *command = (char*)malloc(30 * sizeof(char));
	sprintf(command, "ls %s %s*%s", argv[1], argc > 2 ? argv[2] : "", argc > 3 ? argv[3] : "");
	system(command);
}
