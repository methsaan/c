#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void fitItems(char *item[], int minLen[], int len[], int timeSlotSize[], int lenSize, int timeSlotLen, int itemsPerSlot[timeSlotLen], int outputLens[][lenSize], char *outputItems[][lenSize]) {
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
	for (int x = 0; x < lenSize; x++) {
		len[x] = rand()%(len[x]-minLen[x])+minLen[x];
	}

	int freeTime[timeSlotLen]; // space left in time slot
	for (int x = 0; x < timeSlotLen; x++) {
		freeTime[x] = timeSlotSize[x];
	}
	int spaceTaken[timeSlotLen]; // space taken in time slot
	for (int x = 0; x < timeSlotLen; x++) {
		spaceTaken[x] = 0;
	}
	for (int x = 0; x < timeSlotLen; x++) {
		itemsPerSlot[x] = 0;
	}
	int remainderItems[lenSize]; // items that couldn't fit
	char *remainderItemNames[lenSize];
	int remainderLenIdx[lenSize];
	for (int x = 0; x < lenSize; x++) {
		remainderLenIdx[x] = -1;
	}

	int cnt = 0; // count of items added to slots (doesn't reset)
	int cnt2 = 0; // count of remainder items
	int added[lenSize];
	for (int x = 0; x < lenSize; x++) {
		added[x] = 0;
	}
	for (int x = 0; x < timeSlotLen; x++) {
		for (int y = cnt; y < lenSize; y++) { // looping through items (no repitition outside current loop)
			if (spaceTaken[x]+len[y] <= timeSlotSize[x]) { // if item fits in the gap
				outputLens[x][itemsPerSlot[x]] = len[y]; // add item to the end of time slot row
				outputItems[x][itemsPerSlot[x]] = item[y]; // add item to the end of time slot row
				itemsPerSlot[x]++;
				added[y] = 1;
				spaceTaken[x] += len[y];
				freeTime[x] = timeSlotSize[x]-spaceTaken[x];
				cnt++;
			} else {
				break;
			}
		}
	}
	for (int x = 0; x < lenSize; x++) {
		if (added[x] == 0) {
			remainderItems[cnt2] = len[x];
			remainderItemNames[cnt2] = item[x];
			remainderLenIdx[cnt2] = x;
			cnt2++;
		}
	}
	for (int x = 0; x < timeSlotLen; x++) {
		for (int y = 0; y < cnt2; y++) {
			if (spaceTaken[x]+remainderItems[y] <= timeSlotSize[x]) {
				outputLens[x][itemsPerSlot[x]] = remainderItems[y];
				outputItems[x][itemsPerSlot[x]] = remainderItemNames[y];
				itemsPerSlot[x]++;
				spaceTaken[x] += remainderItems[y];
				freeTime[x] = timeSlotSize[x]-spaceTaken[x];
				added[remainderLenIdx[y]] = 1;
				remainderLenIdx[y] = 0;
				int tempCnt2 = 0;
				for (int a = 0; a < cnt2; a++) {
					if (a != y) {
						remainderItems[tempCnt2] = remainderItems[a];
						remainderItemNames[tempCnt2] = remainderItemNames[a];
						remainderLenIdx[tempCnt2] = remainderLenIdx[a];
						tempCnt2++;
					}
				}
				cnt2 = tempCnt2;
				y--;
			}
		}
	}
	cnt2 = 0;
	for (int x = 0; x < lenSize; x++) {
		if (added[x] == 0) {
			remainderItems[cnt2] = len[x];
			remainderItemNames[cnt2] = item[x];
			remainderLenIdx[cnt2] = x;
			cnt2++;
		}
	}
	for (int x = 0; x < cnt2; x++) {
		int exit = 0;
		for (int y = 0; y < timeSlotLen; y++) {
			int spaceToGain = remainderItems[x]-freeTime[y];
			for (int a = 0; a < itemsPerSlot[y]; a++) {
				for (int b = 0; b < timeSlotLen; b++) {
					if (b != y) {
						for (int c = 0; c < itemsPerSlot[b]; c++) {
							if ((spaceTaken[y]-outputLens[y][a]+outputLens[b][c] < timeSlotSize[y]) && (spaceTaken[b]-outputLens[b][c]+outputLens[y][a] < timeSlotSize[b])) {
								int temp = outputLens[y][a];
								outputLens[y][a] = outputLens[b][c];
								outputLens[b][c] = temp;
								spaceTaken[y] = spaceTaken[y]-outputLens[b][c]+outputLens[y][a];
								spaceTaken[b] = spaceTaken[b]-outputLens[y][a]+outputLens[b][c];
								freeTime[y] = timeSlotSize[y]-spaceTaken[y];
								freeTime[b] = timeSlotSize[b]-spaceTaken[b];
							}
							for (int i = 0; i < timeSlotLen; i++) {
								if (timeSlotSize[i]-spaceTaken[i] > remainderItems[x]) {
									outputLens[i][itemsPerSlot[i]] = remainderItems[x];
									itemsPerSlot[i]++;
									int tempCnt2 = 0;
									for (int a = 0; a < cnt2; a++) {
										if (a != x) {
											remainderItems[tempCnt2] = remainderItems[a];
											tempCnt2++;
										}
									}
									cnt2 = tempCnt2;
									x--;
									exit = 1;
									break;
								}
							}
							if (exit) {
								break;
							}
						}
						if (exit) {
							break;
						}
					}
					if (exit) {
						break;
					}
				}
				if (exit) {
					break;
				}
			}
			if (exit) {
				break;
			}
		}
	}

	for (int x = 0; x < timeSlotLen; x++) {
		if (freeTime[x] > 0) {
			outputLens[x][itemsPerSlot[x]] = freeTime[x];
			outputItems[x][itemsPerSlot[x]] = "FT";
			itemsPerSlot[x]++;
		}
	}
	for (int x = 0; x < timeSlotLen; x++) {
		for (int y = 0; y < itemsPerSlot[x]; y++) {
			int randIdx = rand()%itemsPerSlot[x];
			int temp = outputLens[x][y];
			outputLens[x][y] = outputLens[x][randIdx];
			outputLens[x][randIdx] = temp;
			char *temp2 = outputItems[x][y];
			outputItems[x][y] = outputItems[x][randIdx];
			outputItems[x][randIdx] = temp2;
		}	
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
	size_t malloc_size = 10;
	size_t malloc_size2 = 20;
	size_t malloc_size3 = 30;
	size_t malloc_size4 = 20;

	int minutesOccupied[2880];
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
	timeGapStart[timeGapCnt] = minutesOccupied[minOccCnt-1]+1;
	timeGapLen[timeGapCnt] = 3119-minutesOccupied[minOccCnt-1];
	timeGapCnt++;
	int flexibleItemLen[caCnt+riCnt];
	int flexibleItemMinLen[caCnt+riCnt];
	char *flexibleItems[caCnt+riCnt];
	for (int x = 0; x < riCnt; x++) {
		flexibleItemLen[x] = reqItemMaxLen[x];
		flexibleItemMinLen[x] = reqItemMinLen[x];
		flexibleItems[x] = requiredItems[x];
	}
	for (int x = riCnt; x < caCnt+riCnt; x++) {
		flexibleItemLen[x] = customActivityMaxLen[x-riCnt];
		flexibleItemMinLen[x] = customActivityMinLen[x-riCnt];
		flexibleItems[x] = customActivities[x-riCnt];
	}
	int activitiesPerSlot[timeGapCnt];
	int fitItemLens[timeGapCnt][caCnt+riCnt];
	char *fitItemFunction[timeGapCnt][caCnt+riCnt];
	fitItems(flexibleItems, flexibleItemMinLen, flexibleItemLen, timeGapLen, caCnt+riCnt, timeGapCnt, activitiesPerSlot, fitItemLens, fitItemFunction);
	char *(*fitItem)[caCnt+riCnt];
	fitItem = fitItemFunction;

	int tempSchedItemStart[riCnt+caCnt+fiCnt+1000];
	int tempSchedItemLength[riCnt+caCnt+fiCnt+1000];
	char *tempSchedItem[riCnt+caCnt+fiCnt+1000];
	int tempSchedItemCnt = 0;
	int tempFiCnt = 0;
	for (int x = 0; x < timeGapCnt; x++) {
		int tempFlexStart = timeGapStart[x];
		for (int y = 0; y < activitiesPerSlot[x]; y++) {
			tempSchedItemStart[tempSchedItemCnt] = tempFlexStart;
			tempSchedItem[tempSchedItemCnt] = fitItem[x][y];
			tempSchedItemLength[tempSchedItemCnt] = fitItemLens[x][y];
			tempSchedItemCnt++;
			tempFlexStart += fitItemLens[x][y];
		}
		tempSchedItemStart[tempSchedItemCnt] = tempFlexStart;
		tempSchedItem[tempSchedItemCnt] = fixedItems[tempFiCnt];
		tempSchedItemLength[tempSchedItemCnt] = fixedItemLengthMinutes[tempFiCnt];
		tempSchedItemCnt++;
		tempFlexStart += fixedItemLengthMinutes[tempFiCnt];
		tempFiCnt++;
	}
	for (int x = 0; x < tempSchedItemCnt-1; x++) {
		printf("%02d:%02d %s %d\n", (int)(tempSchedItemStart[x]/60)%24, tempSchedItemStart[x]%60, tempSchedItem[x], tempSchedItemLength[x]);
	}
}
