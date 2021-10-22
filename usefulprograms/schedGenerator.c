#include <stdio.h>
#include <stdlib.h>

int main(int *argc, char *argv[]) {
	size_t malloc_size = 100;

	char *requiredItems[10];
	char *fixedItems[20];
	char *customActivities[30];

	FILE *fp = fopen("requiredItems", "r");

	requiredItems[0] = malloc(malloc_size * sizeof(char));

	int eof = 0;
	int n = 0;
	while (fscanf(fp, "%99s", requiredItems[x]) != EOF) {
		printf("haho %s\n", requiredItems[x]);
		n++;
	}

	for (int x = 0; x < n; x++) {
		
	}

	fclose(fp);
}
