#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int wd(int y, int m, int d) {
	int wday = 0;
	wday = (d + ((153 * (m + 12 * ((14 - m) / 12) - 3) + 2) / 5) + (365 * (y + 4800 - ((14 - m) / 12))) + ((y + 4800 - ((14 - m) / 12)) / 4) - ((y + 4800 - ((14 - m) / 12)) / 100) + ((y + 4800 - ((14 - m) / 12)) / 400) - 32045) % 7;
	return wday;
}

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

int isInArray(int num, int arr[], int len) {
	for (int x = 0; x < len; x++) {
		if (arr[x] == num) {
			return 1;
		}
	}
	return 0;
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
	srand(time(0));

	size_t malloc_size = 10;
	size_t malloc_size2 = 20;
	size_t malloc_size3 = 30;
	size_t malloc_size4 = 20;

	int schedItemStart[100];
	int schedItemLength[100];
	char *schedItem[100];
	int schedItemCnt = 0;

	char *pp[3] = {"PPSR", "PPS", "PPTR"};
	for (int x = 0; x < 3; x++) {
		int randIdx = rand()%3;
		char *temp = pp[x];
		pp[x] = pp[randIdx];
		pp[randIdx] = temp;
	}
	char *ppWeekDist[7];
	int wdCnt = 0;
	for (int x = wdCnt; x < 3; x = wdCnt = x+1) {
		ppWeekDist[x] = pp[0];
	}
	for (int x = wdCnt; x < 5; x = wdCnt = x+1) {
		ppWeekDist[x] = pp[1];
	}
	for (int x = wdCnt; x < 7; x = wdCnt = x+1) {
		ppWeekDist[x] = pp[2];
	}
	time_t tempS, tempVal = 1;
	for (int x = 0; x < 7; x++) {
		int randIdx = rand()%7;
		char *temp = ppWeekDist[x];
		ppWeekDist[x] = ppWeekDist[randIdx];
		ppWeekDist[randIdx] = temp;
	}
	struct tm* tempCurTime;
	tempS = time(NULL);
	tempCurTime = localtime(&tempS);
	int tempD = tempCurTime->tm_mday;
	int tempM = tempCurTime->tm_mon;
	int tempY = tempCurTime->tm_year;
	int weekday = wd(tempY, tempM, tempD);
	if (weekday == 0) {
		FILE *pTracker = fopen("pTracker", "w");
		for (int x = 0; x < 7; x++) {
			fprintf(pTracker, "%s\n", ppWeekDist[x]);
		}
		fclose(pTracker);
	}

	char sched[2];
	printf("Follow recent schedule (f), submit requirement (s), show progress tracker (p) or create new schedule (n)? ");
	scanf("%s", sched);

	if (strcmp(sched, "p") == 0) {
		system("./dayTracker.py");
		return 0;
	}

	if (strcmp(sched, "s") == 0) {
		time_t s, val = 1;
		struct tm* currentTime;
		s = time(NULL);
		currentTime = localtime(&s);

		char monthDay[3];
		sprintf(monthDay, "%02d", currentTime->tm_mday);
		char *months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
		char *dateStr;
		dateStr = malloc(256);
		memset(dateStr, '\0', 256);
		strcat(dateStr, months[currentTime->tm_mon]);
		strcat(dateStr, ". ");
		strcat(dateStr, monthDay);

		char reqMet[10];
		printf("> ");
		scanf("%s", reqMet);
		FILE *reqTracker = fopen("reqTracker", "a");
		fprintf(reqTracker, "---------------\n");
		fprintf(reqTracker, "%s\n", dateStr);
		fprintf(reqTracker, "%s\n", reqMet);
		fclose(reqTracker);
		return 0;
	}

	if (strcmp(sched, "f") == 0) {
		printf("Previously opened schedule:\n");
		char tempLine[40];
		FILE *scheduleRead = fopen("schedule", "r");
		while (fgets(tempLine, 40, scheduleRead)) {
			printf("%s", tempLine);
		}
		fclose(scheduleRead);
	}

	if (strcmp(sched, "n") == 0) {
		int schedLength;
		printf("Enter length of schedule in hours: ");
		scanf("%d", &schedLength);
		char schedStart[6];
		printf("Enter schedule start time: ");
		scanf("%s", schedStart);
		int schedStartInt = ((schedStart[0]-'0')*10+(schedStart[1]-'0'))*60+((schedStart[3]-'0')*10+(schedStart[4]-'0'));

		int minutesOccupied[schedLength*60];
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

		int reqAdd[10];
		printf("Enter requirements to include line by line - PP (0), D (1), MT (2), ST-1 (3), ST-2 (4), ST-3 (5), BL (6), -1 to finish: \n");
		int riCnt = 0;
		for (int x = 0; x < 10; x++) {
			int tempReqAdd;
			scanf("%d", &tempReqAdd);
			if (tempReqAdd == -1) {
				break;
			} else {
				reqAdd[x] = tempReqAdd;
				riCnt++;
			}
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
		int tempRiCnt = 0;
		int tempRiCnt2 = 0;
		int reqItemMinLen[20];
		int reqItemMaxLen[20];
		while (fgets(tempString, 30, reqItemsReader) != NULL) {
			requiredItems[tempRiCnt] = copyString(strtok(tempString, " "));
			reqItemMinLen[tempRiCnt] = atoi(copyString(strtok(NULL, " ")));
			reqItemMaxLen[tempRiCnt] = atoi(copyString(strtok(NULL, " ")));
			tempRiCnt++;
			tempRiCnt2++;
			if (!isInArray(tempRiCnt2-1, reqAdd, riCnt)) {
				tempRiCnt--;
			}
		}
		for (int x = 0; x < riCnt; x++) {
			printf("%s %d %d\n", requiredItems[x], reqItemMinLen[x], reqItemMaxLen[x]);
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
		timeGapStart[0] = schedStartInt;
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
		timeGapLen[timeGapCnt] = (schedStartInt+schedLength*60-1)-minutesOccupied[minOccCnt-1];
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

		int tempFiCnt = 0;
		for (int x = 0; x < timeGapCnt; x++) {
			int tempFlexStart = timeGapStart[x];
			for (int y = 0; y < activitiesPerSlot[x]; y++) {
				schedItemStart[schedItemCnt] = tempFlexStart;
				schedItem[schedItemCnt] = fitItem[x][y];
				schedItemLength[schedItemCnt] = fitItemLens[x][y];
				schedItemCnt++;
				tempFlexStart += fitItemLens[x][y];
			}
			schedItemStart[schedItemCnt] = tempFlexStart;
			schedItem[schedItemCnt] = fixedItems[tempFiCnt];
			schedItemLength[schedItemCnt] = fixedItemLengthMinutes[tempFiCnt];
			schedItemCnt++;
			tempFlexStart += fixedItemLengthMinutes[tempFiCnt];
			tempFiCnt++;
		}
		FILE *schedule = fopen("schedule", "w");
		fprintf(schedule, "_________________\n");
		fprintf(schedule, "| Time| Activity|\n");
		fprintf(schedule, "|_____|_________|\n");
		for (int x = 0; x < schedItemCnt; x++) {
			fprintf(schedule, "|%02d:%02d| %s \t|\n", (int)(schedItemStart[x]/60)%24, schedItemStart[x]%60, schedItem[x], schedItemLength[x]);
		}
		fclose(schedule);

		FILE *schedReader = fopen("schedReader", "w");
		for (int x = 0; x < schedItemCnt; x++) {
			fprintf(schedReader, "%d %d %s %d\n", schedItemCnt, schedItemStart[x], schedItem[x], schedItemLength[x]);
		}
		fclose(schedReader);

		time_t s, val = 1;
		struct tm* currentTime;
		s = time(NULL);
		currentTime = localtime(&s);

		char monthDay[3];
		sprintf(monthDay, "%02d", currentTime->tm_mday);

		char *months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
		char *dateStr;
		dateStr = malloc(256);
		memset(dateStr, '\0', 256);
		strcat(dateStr, months[currentTime->tm_mon]);
		strcat(dateStr, ". ");
		strcat(dateStr, monthDay);

		FILE *schedReader2 = fopen("schedReader2", "w");
		fprintf(schedReader2, "%s\n", dateStr);
		fprintf(schedReader2, "%d\n", schedLength);
		fprintf(schedReader2, "%s\n", schedStart);
		fclose(schedReader);
		printf("_________________\n");
		printf("| Time| Activity|\n");
		printf("|_____|_________|\n");
		for (int x = 0; x < schedItemCnt; x++) {
			printf("|%02d:%02d| %s \t|\n", (int)(schedItemStart[x]/60)%24, schedItemStart[x]%60, schedItem[x], schedItemLength[x]);
		}
	}
	FILE *readpTracker = fopen("pTracker", "r");
	int pLineCnt = 0;
	char pLine[256];
	while (fgets(pLine, sizeof(pLine), readpTracker) != NULL) {
		if (pLineCnt == weekday) {
			printf("PP = %s\n", pLine);
		}
		pLineCnt++;
	}
	fclose(readpTracker);

	if (strcmp(sched, "f") == 0) {
		char tempLine[40];
		int tempCnt = 0;
		FILE *schedReaderRead = fopen("schedReader", "r");
		while (fgets(tempLine, 40, schedReaderRead)) {
			char *tempStr = strtok(tempLine, " ");
			schedItemCnt = atoi(tempStr);
			tempStr = strtok(NULL, " ");
			schedItemStart[tempCnt] = atoi(tempStr);
			tempStr = strtok(NULL, " ");
			schedItem[tempCnt] = (char *) malloc(100);
			memset(schedItem[tempCnt], '\0', 100);
			strcpy(schedItem[tempCnt], tempStr);
			tempStr = strtok(NULL, " ");
			schedItemLength[tempCnt] = atoi(tempStr);
			tempCnt++;
		}
	}

	printf("Requirement check:\n");

	int onTime[schedItemCnt];
	char reqMet[schedItemCnt][7][15];
	int reqMetCntPerItem[schedItemCnt];
	for (int x = 0; x < schedItemCnt; x++) {
		reqMetCntPerItem[x] = 0;
	}
	time_t s, val = 1;
	struct tm* currentTime;
	s = time(NULL);
	currentTime = localtime(&s);

	char monthDay[3];
	sprintf(monthDay, "%02d", currentTime->tm_mday);
	char *months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
	char *dateStr;
	dateStr = malloc(256);
	memset(dateStr, '\0', 256);
	strcat(dateStr, months[currentTime->tm_mon]);
	strcat(dateStr, ". ");
	strcat(dateStr, monthDay);
	system("touch tempSchedTracker");

	for (int x = 0; x < schedItemCnt-1; x++) {
		printf("%02d:%02d (%s) - already tracked (-1), on time (3), late (1), or unfinished (0)? ", (int)(schedItemStart[x]/60)%24, schedItemStart[x]%60, schedItem[x]);
		scanf("%d", &onTime[x]);
		if (onTime[x] == -1) {
			char tempSchedTrackerStr[3];
			FILE *tempSchedTrackerRead = fopen("tempSchedTracker", "r");
			for (int y = 0; y < x+1; y++) {
				fgets(tempSchedTrackerStr, 3, tempSchedTrackerRead);
				tempSchedTrackerStr[strlen(tempSchedTrackerStr)-1] = '\0';
			}
			fclose(tempSchedTrackerRead);
			onTime[x] = atoi(tempSchedTrackerStr);
			continue;
		}else {
			FILE *tempSchedTracker = fopen("tempSchedTracker", "a");
			fprintf(tempSchedTracker, "%d\n", onTime[x]);
			fclose(tempSchedTracker);
		}
		for (int y = 0; y < 7; y++) {
			printf("> ");
			scanf("%s", reqMet[x][y]);
			if (strcmp(reqMet[x][y], "-") == 0) {
				break;
			}
			FILE *reqTracker = fopen("reqTracker", "a");
			fprintf(reqTracker, "---------------\n");
			fprintf(reqTracker, "%s\n", dateStr);
			fprintf(reqTracker, "%s\n", reqMet[x][y]);
			fclose(reqTracker);
			reqMetCntPerItem[x]++;
		}
	}

	double onTimeAvg = 0;
	for (int x = 0; x < schedItemCnt; x++) {
		onTimeAvg += onTime[x];
	}
	onTimeAvg /= schedItemCnt-1;
	char startDateStr[15];
	char schedLengthRead[15];
	char schedStartRead[15];
	FILE *schedReaderRead2 = fopen("schedReader2", "r");
	fgets(startDateStr, 15, schedReaderRead2);
	startDateStr[strlen(startDateStr)-1] = '\0';
	fgets(schedLengthRead, 15, schedReaderRead2);
	fgets(schedStartRead, 15, schedReaderRead2);
	schedStartRead[strlen(schedStartRead)-1] = '\0';
	fclose(schedReaderRead2);
	FILE *schedTracker = fopen("schedTracker", "a");
	char schedEnd[6] = "";
	int schedEndInt = (((schedStartRead[0]-'0')*10+(schedStartRead[1]-'0'))*60+((schedStartRead[3]-'0')*10+(schedStartRead[4]-'0')) + atoi(schedLengthRead)*60) % 1440;
	char tempSchedEndAdd[3];
	sprintf(tempSchedEndAdd, "%02d", schedEndInt/60);
	strcat(schedEnd, tempSchedEndAdd);
	strcat(schedEnd, ":");
	sprintf(tempSchedEndAdd, "%02d", schedEndInt%60);
	strcat(schedEnd, tempSchedEndAdd);
	fprintf(schedTracker, "%s %s - %s %s %f\n", startDateStr, schedStartRead, dateStr, schedEnd, onTimeAvg);
	fclose(schedTracker);
	system("rm tempSchedTracker");
}
