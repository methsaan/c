#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
	srand(time(NULL));
	while (1) {
		char str1[2];
		snprintf(str1, 2, "%d", (rand()%400)+1);
		char str2[2];
		snprintf(str2, 2, "%d", (rand()%400)+1);
		printf("\033[%s;%sHx\n\n\n", str1, str2);
		for (long long int x = 0; x < 10000000; x++) {
			;
		}
	}
}
