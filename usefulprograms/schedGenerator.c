#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int *argc, char *argv[]) {
	size_t malloc_size = 15;
	size_t malloc_size2 = 30;
	size_t malloc_size3 = 30;

	char *requiredItems[10];
	for (int x = 0; x < 10; x++) {
		requiredItems[x] = malloc(malloc_size * sizeof(char));
	}
	int requiredItemMinutes[20];
	char *fixedItems[20];
	for (int x = 0; x < 20; x++) {
		fixedItems[x] = malloc(malloc_size2 * sizeof(char));
	}
	int fixedItemMinutes[20];
	char *customActivities[30];
	for (int x = 0; x < 30; x++) {
		fixedItems[x] = malloc(malloc_size3 * sizeof(char));
	}
	int customActivityMinutes[20];
	

	FILE *fp = fopen("requiredItems", "r");

	int riCnt = 0;
	while (fscanf(fp, "%14s", requiredItems[riCnt]) != EOF) {
		riCnt++;
	}

	int fiCnt = 0;
	printf("Enter fixed items (enter q when done):\n");
	do {
		scanf("%29s", fixedItems[fiCnt]);
		fiCnt++;
	} while (fixedItems[fiCnt-1][0] != 'q');
	for (int x = 0; x < fiCnt; x++) {
		printf("%s\n", fixedItems[x]);
	}

	fclose(fp);
}
