#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void fitItems(char *item[], int minLen[], int len[], int timeSlotStart[], int timeSlotSize[], int lenSize, int timeSlotLen, int outputLens[][lenSize]) {
	srand(time(0));
	//for (int x = 0; x < lenSize; x++) { // randomize item[], minLen[] and len[]
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
			remainderLenIdx[cnt2] = x;
			cnt2++;
		}
	}
	for (int x = 0; x < timeSlotLen; x++) {
		printf("%d: ", timeSlotSize[x]);
		for (int y = 0; y < itemsPerSlot[x]; y++) {
			printf("%d ", outputLens[x][y]);
		}
		printf("\n");
	}
	for (int x = 0; x < cnt2; x++) {
		printf("%d ", remainderItems[x]);
	}
	printf("\n");
	for (int x = 0; x < timeSlotLen; x++) {
		for (int y = 0; y < cnt2; y++) {
			if (spaceTaken[x]+remainderItems[y] <= timeSlotSize[x]) {
				outputLens[x][itemsPerSlot[x]] = remainderItems[y];
				itemsPerSlot[x]++;
				spaceTaken[x] += remainderItems[y];
				freeTime[x] = timeSlotSize[x]-spaceTaken[x];
				added[remainderLenIdx[y]] = 1;
				remainderLenIdx[y] = 0;
				int tempCnt2 = 0;
				for (int a = 0; a < cnt2; a++) {
					if (a != y) {
						remainderItems[tempCnt2] = remainderItems[a];
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
			remainderLenIdx[cnt2] = x;
			cnt2++;
		}
	}
	printf("Before space-making 2:\n");
	for (int x = 0; x < lenSize; x++) {
		printf("%d ", len[x]);
	}
	printf("\n");
	for (int x = 0; x < timeSlotLen; x++) {
		printf("%d: ", timeSlotSize[x]);
		for (int y = 0; y < itemsPerSlot[x]; y++) {
			printf("%d ", outputLens[x][y]);
		}
		printf("\n");
	}
	for (int x = 0; x < lenSize; x++) {
		printf("%d: %d\n", len[x], added[x]);
	}
	printf("\n");
	for (int x = 0; x < timeSlotLen; x++) {
		printf("%d: %d\n", timeSlotSize[x], itemsPerSlot[x]);
	}
	for (int x = 0; x < timeSlotLen; x++) {
		printf("%d free %d\n", x, freeTime[x]);
		printf("%d used %d\n", x, spaceTaken[x]);
	}
	printf("\n\n");
	for (int x = 0; x < cnt2; x++) {
		int exit = 0;
		for (int y = 0; y < timeSlotLen; y++) {
			int spaceToGain = remainderItems[x]-freeTime[y];
			for (int a = 0; a < itemsPerSlot[y]; a++) {
				printf("\toutputLens[y][a]: %d\n", outputLens[y][a]);
				for (int b = 0; b < timeSlotLen; b++) {
					if (b != y) {
						for (int c = 0; c < itemsPerSlot[b]; c++) {
							printf("\t\toutputLens[b][c]: %d\n\n", outputLens[b][c]);
							printf("\t\tspaceTaken[y]: %d\n", spaceTaken[y]);
							printf("\t\toutputLens[y][a]: %d\n", outputLens[y][a]);
							printf("\t\toutputLens[b][c]: %d\n", outputLens[b][c]);
							printf("\t\tspaceTaken[y]-outputLens[y][a]+outputLens[b][c]: %d\n", spaceTaken[y]-outputLens[y][a]+outputLens[b][c]);
							printf("\t\tspaceTaken[b]: %d\n", spaceTaken[b]);
							printf("\t\tspaceTaken[b]-outputLens[b][c]+outputLens[y][a]: %d\n", spaceTaken[b]-outputLens[b][c]+outputLens[y][a]);
							if ((spaceTaken[y]-outputLens[y][a]+outputLens[b][c] < timeSlotSize[y]) && (spaceTaken[b]-outputLens[b][c]+outputLens[y][a] < timeSlotSize[b])) {
								printf("YES\n");
								int temp = outputLens[y][a];
								outputLens[y][a] = outputLens[b][c];
								outputLens[b][c] = temp;
								spaceTaken[y] = spaceTaken[y]-outputLens[b][c]+outputLens[y][a];
								spaceTaken[b] = spaceTaken[b]-outputLens[y][a]+outputLens[b][c];
								freeTime[y] = timeSlotSize[y]-spaceTaken[y];
								freeTime[b] = timeSlotSize[b]-spaceTaken[b];
							}
							for (int i = 0; i < timeSlotLen; i++) {
								printf("%d: ", timeSlotSize[i]);
								for (int j = 0; j < itemsPerSlot[i]; j++) {
									printf("%d ", outputLens[i][j]);
								}
								printf("\n");
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

	printf("After space-making:\n");
	for (int x = 0; x < lenSize; x++) {
		printf("%d ", len[x]);
	}
	printf("\n");
	for (int x = 0; x < timeSlotLen; x++) {
		printf("%d: ", timeSlotSize[x]);
		for (int y = 0; y < itemsPerSlot[x]; y++) {
			printf("%d ", outputLens[x][y]);
		}
		printf("\n");
	}
	printf("cnt2: %d\n", cnt2);
}

void waaaa(int i, int j, char *aaa[], char *wa[][j]) {
	for (int x = 0; x < i; x++) {
		for (int y = 0; y < j; y++) {
			wa[x][y] = aaa[y];
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
	char *a[] = {"PA", "PP", "MT", "ST", "D", "Volunteer", "x"};
	int b[] = {35, 50, 70, 35, 30, 20, 25};
	int c[] = {20, 30, 60, 35, 20, 15, 15};
	int d[] = {310, 540, 880};
	int e[] = {95, 40, 145};
	int f[3][7];
	char *g[3][7];
	fitItems(a, c, b, d, e, 7, 3, f);

	//printf("\n");

	//int d[] = {310, 540, 880};
	//int c[] = {20, 30, 30, 15, 20, 45, 35};
	//int d[] = {310, 540, 880};
	//int c[] = {20, 30, 30, 15, 20, 45, 35};

	int m = 14;
	int n = 5;
	char *ouih[5];
	ouih[0] = "igyuiugiug";
	ouih[1] = "iugiubgi";
	ouih[2] = "mjbiuv";
	ouih[3] = "uvfuhjybkjnmmm";
	ouih[4] = "trcd";
	char *h[m][n];
	waaaa(m, n, ouih, h);
	char *(*h2)[n];
	h2 = h;

	//for (int d = 0; d < m; d++) {
	//	for (int e = 0; e < n; e++) {
	//		printf("%s ", *(*(h2 + d) + e));
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
