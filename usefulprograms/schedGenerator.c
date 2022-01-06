#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void getWords(char *base, char target[6][20]) {
	int n = 0, i, j = 0;
	for (i = 0; 1; i++) {
		if (base[i] != ' ') {
			target[n][j++] = base[i];
		} else {
			target[n][j++] = '\0';
			n++;
			j = 0;
		}
		if (base[i] == '\n') {
			break;
		}
	}
}

char *copyString(char s[]) {
	char* s2;
	s2 = (char*)malloc(3);
	strcpy(s2, s);
	return (char*)s2;
}

int main(int *argc, char *argv[]) {
	size_t malloc_size = 15;
	size_t malloc_size2 = 30;
	size_t malloc_size3 = 30;

	int minutesOccupied[1440];
	int minOccCnt = 0;
	int timeGapStart[120];
	int timeGapLen[120];
	int timeGapCnt = 0;

	int requiredItemStartMinutes[20];
	int requiredItemEndMinutes[20];
	int requiredItemLengthMinutes[20];
	char *requiredItems[10];
	char requiredItemsStr[30];
	for (int x = 0; x < 10; x++) {
		requiredItems[x] = malloc(malloc_size * sizeof(char));
	}

	int fixedItemStartMinutes[20];
	int fixedItemEndMinutes[20];
	int fixedItemLengthMinutes[20];
	char *fixedItems[20];
	for (int x = 0; x < 20; x++) {
		fixedItems[x] = malloc(malloc_size2 * sizeof(char));
	}

	int customActivityStartMinutes[20];
	int customActivityEndMinutes[20];
	int customActivityLengthMinutes[20];
	char *customActivities[30];
	for (int x = 0; x < 30; x++) {
		customActivities[x] = malloc(malloc_size3 * sizeof(char));
	}

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
		int minutesTot2 = hoursTot2*60 + (endTime[3]-'0')*10 + (endTime[4]-'0');
		fixedItemEndMinutes[fiCnt] = minutesTot2;
		fixedItemLengthMinutes[fiCnt] = minutesTot2 - minutesTot;
		fiCnt++;
	}
	for (int x = 0; x < fiCnt; x++) {
		for (int i = fixedItemStartMinutes[x]; i < fixedItemEndMinutes[x]; i++) {
			minutesOccupied[minOccCnt] = i;
			minOccCnt++;
		}
	}
	FILE *reqItemsReader = fopen("requiredItems", "r");

	char tempString[30];
	int riCnt = 0;
	char *reqItemMinLen[20];
	char *reqItemMaxLen[20];
	while (fgets(tempString, 30, reqItemsReader) != NULL) {
		requiredItems[riCnt] = copyString(strtok(tempString, " "));
		reqItemMinLen[riCnt] = copyString(strtok(NULL, " "));
		reqItemMaxLen[riCnt] = copyString(strtok(NULL, " "));
		riCnt++;
	}

	int caCnt = 0;
	char *customActivityMinLen[20];
	char *customActivityMaxLen[20];
	while (1) {
		customActivities[caCnt] = copyString(strtok(tempString, " "));
		customActivityMinLen[caCnt] = copyString(strtok(NULL, " "));
		customActivityMaxLen[caCnt] = copyString(strtok(NULL, " "));
		caCnt++;
		if (*customActivityMinLen[0] == '-' || *customActivityMaxLen[0] == '-') {
			break;
		}
	}

	for (int x = 1; x < minOccCnt; x++) {
		if ((minutesOccupied[x]-minutesOccupied[x-1]) > 1) {
			timeGapStart[timeGapCnt] = minutesOccupied[x-1];
			timeGapLen[timeGapCnt] = minutesOccupied[x]-minutesOccupied[x-1];
			timeGapCnt++;
		}
	}

	for (int x = 0; x < fiCnt; x++) {
		printf("%s %d %d %d\n", fixedItems[x], fixedItemStartMinutes[x], fixedItemEndMinutes[x], fixedItemLengthMinutes[x]);
	}
	for (int x = 0; x < riCnt; x++) {
		printf("%s %s %s\n", requiredItems[x], reqItemMinLen[x], reqItemMaxLen[x]);
	}
	for (int x = 0; x < caCnt; x++) {
		printf("%s %s %s\n", customActivities[x], customActivityMinLen[x], customActivityMaxLen[x]);
	}
}
