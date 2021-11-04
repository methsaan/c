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

int main(int *argc, char *argv[]) {
	size_t malloc_size = 15;
	size_t malloc_size2 = 30;
	size_t malloc_size3 = 30;

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

	FILE *fp = fopen("requiredItems", "r");

	int riCnt = 0;
	while (fgets(requiredItemsStr, 30, fp)) {
		printf("line %d: %s\n", riCnt+1, requiredItemsStr);
		char requiredItemsInfo[6][20];
		getWords(requiredItemsStr, requiredItemsInfo);
		requiredItems[riCnt] = requiredItemsInfo[0];
		// only printing last line
		printf("%s %s %s\n", requiredItemsInfo[0], requiredItemsInfo[1], requiredItemsInfo[2]);
		riCnt++;
	}
	fclose(fp);

	//PA 030-050
	//PA 030-050
	//PP 050-080
	//D 025-045
	//MT 025-45
	//ST 035-060
	for (int x = 0; x < fiCnt; x++) {
		printf("%s %d %d\n", fixedItems[x], fixedItemStartMinutes[x], fixedItemEndMinutes[x]);
	}
	for (int x = 0; x < riCnt; x++) {
		printf("%s\n", requiredItems[x]);
	}
}
