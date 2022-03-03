#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//void *fitItems(char *item[], int minLen[], int len[], int lenSize, int timeSlotStart[], int timeSlotSize[], int timeSlotLen, int **newItemLens, char ***newItems) {
	//item, minimum length, maximum length, size of first 3 arrays, time slot start, time slot size, length of previous 2 arrays, returned length array, return item arr
	srand(time(0));

	//for (int x = 0; x < lenSize; x++) {
	//	int randIdx = rand()%lenSize;
	//	int temp = len[x];
	//	len[x] = len[randIdx];
	//	len[randIdx] = temp;
	//	temp = minLen[x];
	//	minLen[x] = minLen[randIdx];
	//	minLen[randIdx] = temp;
	//	char *temp2 = item[x];
	//	item[x] = item[randIdx];
	//	item[randIdx] = temp2;
	//}

	//newItemLens = malloc(timeSlotLen*sizeof(int *)); // final item lengths for each time length
	//for (int x = 0; x < timeSlotLen; x++) {
	//	newItemLens[x] = malloc(lenSize*sizeof(int));
	//}

	//int **tempItemMinLens = malloc(timeSlotLen*sizeof(int *)); // used for making space for remainder

	//for (int x = 0; x < timeSlotLen; x++) {
	//	tempItemMinLens[x] = malloc(lenSize*sizeof(int));
	//}

	//int cnt = 0; // count of items that have been added
	//int minPerSlot[timeSlotLen]; // track of minutes in each gap
	//for (int x = 0; x < timeSlotLen; x++) {
	//	minPerSlot[x] = 0;
	//}
	//int remainderItems[lenSize]; // items that couldn't fit in gaps
	//int remCnt = 0; // count of remainder items
	//int fitItemsCnt[timeSlotLen]; // count of items in each time gap
	//for (int x = 0; x < timeSlotLen; x++) {
	//	fitItemsCnt[x] = 0;
	//}

	//for (int x = 0; x < lenSize; x++) { // loop through timeslots for each item, x represents item, y represents gap
	//	int tempCnt = cnt;
	//	for (int y = 0; y < timeSlotLen; y++) {
	//		if (minPerSlot[y]+len[x] < timeSlotSize[y]) { // making sure total item length fits gap
	//			minPerSlot[y] += len[x]; // adds item length to minutes per slot
	//			newItemLens[y][cnt] = len[x]; // adds item length to final array
	//			tempItemMinLens[y][cnt] = minLen[x];
	//			fitItemsCnt[y]++; // count of items in gap increases
	//			cnt++;
	//			break; // moves on to the next item
	//		}
	//	}
	//	if (tempCnt == cnt) { // only runs if the item was not added
	//		remainderItems[remCnt] = len[x]; // adds item to items that couldn't fit gaps array
	//		remCnt++;
	//	}
	//}

	//for (int x = 0; x < timeSlotLen; x++) {
	//	for (int y = 0; y < timeSlotLen; y++) {
	//		if (timeSlotSize[x] < timeSlotSize[y]) {
	//			int temp = timeSlotSize[x];
	//			timeSlotSize[x] = timeSlotSize[y];
	//			timeSlotSize[y] = temp;
	//		}
	//	}
	//}

	//for (int y = 0; y < remCnt; y++) {
	//	int remAdded = 0;
	//	for (int x = 0; x < timeSlotLen; x++) {
	//		for (int z = 0; z < lenSize; z++) { // items in newItemLens (each time slot)
	//			if (newItemLens[x][z]-tempItemMinLens[x][z] >= remainderItems[y]) {
	//				newItemLens[x][z] -= remainderItems[y];
	//				newItemLens[x][fitItemsCnt[x]] = remainderItems[y];
	//				tempItemMinLens[x][fitItemsCnt[x]] = remainderItems[y];
	//				fitItemsCnt[x]++;
	//				remAdded = 1;
	//				break;
	//			}
	//		}
	//		if (remAdded) {
	//			break;
	//		}
	//	}
	//}
	//for (int x = 0; x < timeSlotLen; x++) {
	//	for (int y = 0; y < lenSize; y++) {
	//		printf("%d ", newItemLens[x][y]);
	//	}
	//	printf("\n");
	//}
//}

void waaa

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
	s2 = (char*)malloc(10);
	strcpy(s2, s);
	return (char*)s2;
}

int main(int *argc, char *argv[]) {
	//char *a[] = {"PA", "PP", "MT", "ST", "D", "Volunteer", "x"};
	//int b[] = {30, 40, 50, 30, 40, 60, 75};
	//int c[] = {20, 30, 30, 15, 20, 45, 35};
	//int d[] = {310, 540, 880};
	//int e[] = {80, 200, 100};
	//int f[][] = (int*)malloc(7*sizeof(int));
	//char *g[] = (char**)malloc(7*sizeof(char**));
	//fitItems(a, b, c, 7, d, e, 3, f, g);
	//printf("\n");

	size_t malloc_size = 10;
	size_t malloc_size2 = 20;
	size_t malloc_size3 = 30;
	size_t malloc_size4 = 20;

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
	int reqItemMinLen[20];
	int reqItemMaxLen[20];
	while (fgets(tempString, 30, reqItemsReader) != NULL) {
		requiredItems[riCnt] = copyString(strtok(tempString, " "));
		reqItemMinLen[riCnt] = atoi(copyString(strtok(NULL, " ")));
		reqItemMaxLen[riCnt] = atoi(copyString(strtok(NULL, " ")));
		riCnt++;
	}

	int caCnt = 0;
	int customActivityMinLen[20];
	int customActivityMaxLen[20];
	printf("Enter custom activities, minimum time and maximum time separated by a space (enter '-1 -1 -1' when done):\n");
	while (1) {
		scanf("%s %d %d", customActivities[caCnt], &customActivityMinLen[caCnt], &customActivityMaxLen[caCnt]);
		if (customActivityMinLen[caCnt] == -1 && customActivityMaxLen[caCnt] == -1) {
			break;
		}
		caCnt++;
	}
	timeGapStart[0] = 280;
	timeGapLen[0] = minutesOccupied[0]-timeGapStart[0];
	timeGapCnt++;
	for (int x = 1; x < minOccCnt; x++) {
		if ((minutesOccupied[x]-minutesOccupied[x-1]) > 1) {
			timeGapStart[timeGapCnt] = minutesOccupied[x-1]+1;
			timeGapLen[timeGapCnt] = minutesOccupied[x]-minutesOccupied[x-1]-1;
			timeGapCnt++;
		}
	}
	printf("\n");
	timeGapStart[timeGapCnt] = minutesOccupied[minOccCnt-1]+1;
	timeGapLen[timeGapCnt] = 1169-minutesOccupied[minOccCnt-1];
	timeGapCnt++;
	for (int x = 0; x < timeGapCnt; x++) {
		printf("%d + %d, ", timeGapStart[x], timeGapLen[x]);
	}
	printf("\n");
	int flexibleItemLen[caCnt+riCnt];
	for (int x = 0; x < caCnt; x++) {
		flexibleItemLen[x] = customActivityMaxLen[x];
	}
	for (int x = caCnt; x < caCnt+riCnt; x++) {
		flexibleItemLen[x] = reqItemMaxLen[x];
	}

	for (int x = 0; x < caCnt+riCnt; x++) {
		
	}

	for (int x = 0; x < fiCnt; x++) {
		printf("%s %d %d %d\n", fixedItems[x], fixedItemStartMinutes[x], fixedItemEndMinutes[x], fixedItemLengthMinutes[x]);
	}
	for (int x = 0; x < riCnt; x++) {
		printf("%s %d %d\n", requiredItems[x], reqItemMinLen[x], reqItemMaxLen[x]);
	}
	for (int x = 0; x < caCnt; x++) {
		printf("%s %d %d\n", customActivities[x], customActivityMinLen[x], customActivityMaxLen[x]);
	}
}
