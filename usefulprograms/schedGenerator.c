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
	int requiredItemStartMinutes[20];
	int requiredItemEndMinutes[20];
	char *fixedItems[20];
	for (int x = 0; x < 20; x++) {
		fixedItems[x] = malloc(malloc_size2 * sizeof(char));
	}
	int fixedItemStartMinutes[20];
	int fixedItemLengthMinutes[20];
	char *customActivities[30];
	for (int x = 0; x < 30; x++) {
		customActivities[x] = malloc(malloc_size3 * sizeof(char));
	}
	int customActivityStartMinutes[20];
	int customActivityLengthMinutes[20];

	FILE *fp = fopen("requiredItems", "r");

	int riCnt = 0;
	while (fscanf(fp, "%14s", requiredItems[riCnt]) != EOF) {
		riCnt++;
	}
	fclose(fp);

	int fiCnt = 0;
	printf("Enter fixed items, start time and end time separated by a space (enter '- - -' when done):\n");
	while (1) {
		char startTime[6];
		char endTime[6];
		scanf("%s %s %s", fixedItems[fiCnt], startTime, endTime);
		if (startTime[0] == '-' || endTime[0] == '-') {
			break;
		}
		int hoursTot = (startTime[0]-'0')*10 + (startTime[1]-'0');
		int minutesTot = hoursTot*60 + (startTime[3]-'0')*10 + (startTime[4]-'0');
		fixedItemStartMinutes[fiCnt] = minutesTot;
		int hoursTot2 = (endTime[0]-'0')*10 + (endTime[1]-'0');

		// calculate length of activity (minutesTot2-minutesTot) doesn't work

		int minutesTot2 = hoursTot2*60 + (endTime[3]-'0')*10 + (endTime[4]-'0');
		fixedItemLengthMinutes[fiCnt] = minutesTot2 - minutesTot;
		fiCnt++;
	}
	//PA 030-050
	//PA 030-050
	//PP 050-080
	//D 025-045
	//MT 025-45
	//ST 035-060
	for (int x = 0; x < fiCnt; x++) {
		printf("%s %d %d\n", fixedItems[x], fixedItemStartMinutes[x], fixedItemLengthMinutes[x]);
	}
}
