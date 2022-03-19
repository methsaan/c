#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void fitItems(char *item[], int minLen[], int len[], int timeSlotStart[], int timeSlotSize[], int lenSize, int timeSlotLen, int outputLens[][lenSize]) {
	srand(time(0));

	for (int x = 0; x < lenSize; x++) { // randomize item[], minLen[] and len[]
		int randIdx = rand()%lenSize;
		int temp = len[x];
		len[x] = len[randIdx];
		len[randIdx] = temp;
		temp = minLen[x];
		minLen[x] = minLen[randIdx];
		minLen[randIdx] = temp;
		char *temp2 = item[x];
		item[x] = item[randIdx];
		item[randIdx] = temp2;
	}

	outputLens = malloc(timeSlotLen*sizeof(int *)); // initialize outputLens
	for (int x = 0; x < timeSlotLen; x++) {
		outputLens[x] = malloc(lenSize*sizeof(int));
	}

	int freeTime[timeSlotLen]; // space left in time slot
	for (int x = 0; x < timeSlotLen; x++) {
		freeTime[x] = timeSlotSize[x];
	}
	int spaceTaken[timeSlotLen]; // space taken in time slot
	for (int x = 0; x < timeSlotLen; x++) {
		spaceTaken[x] = 0;
	}
	int itemsPerSlot[timeSlotLen]; // num of items in time slot
	for (int x = 0; x < timeSlotLen; x++) {
		itemsPerSlot[x] = 0;
	}
	int remainderItems[lenSize]; // items that couldn't fit

	int cnt = 0; // count of items added to slots (doesn't reset)
	int cnt2 = 0; // count of remainder items
	for (int x = 0; x < timeSlotLen; x++) {
		for (int y = cnt; y < lenSize; y++) { // looping through items (no repitition outside current loop)
			if (spaceTaken[x]+len[y] <= timeSlotSize[x]) { // if item fits in the gap
				outputLens[x][itemsPerSlot[x]] = len[y]; // add item to the end of time slot row
				itemsPerSlot[x]++;
				spaceTaken[x] += len[y];
				freeTime[x] = timeSlotSize[x]-spaceTaken[x];
				cnt++;
			} else {
				break;
			}
		}
	}
	int added[lenSize];
	for (int x = 0; x < lenSize; x++) {
		added[x] = 0;
	}
	for (int x = 0; x < lenSize; x++) {
		for (int y = 0; y < timeSlotLen; y++) {
			for (int z = 0; z < itemsPerSlot[x]; z++) {
				if (len[x] == outputLens[y][z]) {
					added[x] = 1;
				}
			}
		}
	}
	for (int x = 0; x < lenSize; x++) {
		if (added[x] == 0) {
			remainderItems[cnt2] = len[x];
			cnt2++;
		}
	}
	// continue here .....................................................................
	while (1) {
		int tempCnt2 = cnt2;
		for (int x = 0; x < timeSlotLen; x++) {
			for (int y = 0; y < itemsPerSlot[x]; y++) { // x and y loop through items in outputLens
				for (int a = 0; a < timeSlotLen; a++) {
					if (a != x) { // time slots need to be different in order for space to increase
						for (int b = 0; b < itemsPerSlot[x]; b++) {
							if (spaceTaken[x]-outputLens[x][y]+outputLens[a][b] <= spaceTaken[x]) {
								int temp = outputLens[x][y];
								outputLens[x][y] = outputLens[a][b];
								outputLens[a][b] = temp;
								spaceTaken[x] = spaceTaken[x]-outputLens[x][y]+outputLens[a][b];
								spaceTaken[a] = spaceTaken[a]-outputLens[a][b]+outputLens[x][y];
								freeTime[x] = timeSlotSize[x]-spaceTaken[x];
								freeTime[a] = timeSlotSize[a]-spaceTaken[a];
							}
						}
					}
				}
			}
			for (int x2 = 0; x2 < timeSlotLen; x2++) {
				for (int y2 = 0; y2 < cnt2; y2++) {
					if (freeTime[x2] > remainderItems[y2]) {
						outputLens[x2][itemsPerSlot[x2]] = remainderItems[y2];
						itemsPerSlot[x2]++;
						int tempCnt2 = 0;
						for (int i = 0; i < cnt2; i++) {
							if (i != y2) {
								remainderItems[tempCnt2] = remainderItems[i];
								tempCnt2++;
							}
						}
						cnt2 = tempCnt2;
					}
				}
			}
		}
		if (cnt2 == 0 || tempCnt2 == cnt2) {
			break;
		}
	}
}

void waaaa(int i, int j, int wa[][j]) {
	for (int x = 0; x < i; x++) {
		for (int y = 0; y < j; y++) {
			wa[x][y] = y;
			printf("%d ", wa[x][y]);
		}
		printf("\n");
	}
	int **tempItemMinLens = malloc(12*sizeof(int *));

	for (int x = 0; x < 12; x++) {
		tempItemMinLens[x] = malloc(7*sizeof(int));
	}
}

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


	//int d[] = {310, 540, 880};
	//int c[] = {20, 30, 30, 15, 20, 45, 35};
	//int d[] = {310, 540, 880};
	//int c[] = {20, 30, 30, 15, 20, 45, 35};


	//int f = 14;
	//int g = 5;
	//int h[f][g];
	//waaaa(f, g, h);
	//int (*h2)[g];
	//h2 = h;

	//for (int d = 0; d < f; d++) {
	//	for (int e = 0; e < g; e++) {
	//		printf("%d.0 ", *(*(h2 + d) + e));
	//	}
	//	printf("\n");
	//}

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
