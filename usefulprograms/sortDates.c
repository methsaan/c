#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <math.h>

int dateLen = 12;

char **getLines(char fileName[], int numOfLines) {
	FILE *datesFileRead = fopen(fileName, "r");
	if (datesFileRead == NULL) {
		perror("Error opening file");
		return NULL;
	}

	char **lines = malloc(numOfLines * sizeof(char *));
	if (!lines) {
		return NULL;
	}

	int cnt = 0;
	char line[dateLen];
	while (fgets(line, dateLen, datesFileRead)) {
		lines[cnt] = malloc(dateLen * sizeof(char));
		if (!lines[cnt]) {
			for (int i = 0; i < cnt; i++) {
				free(lines[i]);
			}
			free(lines);
			return NULL;
		}
		snprintf(lines[cnt], dateLen, line, cnt);
		cnt++;
	}
	return lines;
}

int *sortedDatesStartPos(char **datesLines, int numOfLines, char timeUnit[], int *numOfUnits) {
	time_t seconds;
	seconds = time(NULL);
	*numOfUnits = strcmp(timeUnit, "month") == 0 ? 12 :
	        (strcmp(timeUnit, "date") == 0 ? 31 :
	         ceil(seconds / 60 / 60 / 24 / 365) + 1);
	int* startPositions = malloc(*numOfUnits * sizeof(int));
	if (startPositions == NULL) {
	        return NULL;
	}
	memset(startPositions, 0, *numOfUnits * sizeof(int));
	
	for (int i = 0; i < numOfLines; i++) {
		char timeUnitStr[5];
		if (strcmp(timeUnit, "year") == 0) {
			strncpy(timeUnitStr, datesLines[i] + 6, 4);
			timeUnitStr[4] = '\0';
		} else if (strcmp(timeUnit, "month") == 0) {
			strncpy(timeUnitStr, datesLines[i] + 3, 2);
			timeUnitStr[2] = '\0';
		} else {
			strncpy(timeUnitStr, datesLines[i], 2);
			timeUnitStr[2] = '\0';
		}
		if (strcmp(timeUnit, "year") == 0) {
			startPositions[atoi(timeUnitStr) - 1970] += 1;
		} else {
			startPositions[atoi(timeUnitStr) - 1] += 1;
		}
	}
	for (int i = 1; i < *numOfUnits; i++) {
		startPositions[i] += startPositions[i - 1];
	}
	for (int i = *numOfUnits - 1; i > 0; i--) {
		startPositions[i] = startPositions[i - 1];
	}
	startPositions[0] = 0;
	return startPositions;
}

char **sortByTimeUnit(char **unsortedDates, int numOfLines, char timeUnit[]) {
	int numOfTimeUnits;
	int *startPos = sortedDatesStartPos(unsortedDates, numOfLines, timeUnit, &numOfTimeUnits);
	if (!startPos) {
		perror("Error getting start positions");
		return NULL;
	}
	char **sortedByTimeUnit = malloc(numOfLines * sizeof(*unsortedDates));
	if (!sortedByTimeUnit) {
		perror("Malloc");
		return NULL;
	}
	for (int i = 0; i < numOfLines; i++) {
		char timeUnitStr[5];
		if (strcmp(timeUnit, "date") == 0) {
			strncpy(timeUnitStr, unsortedDates[i], 2);
			timeUnitStr[2] = '\0';
		} else if (strcmp(timeUnit, "month") == 0) {
			strncpy(timeUnitStr, unsortedDates[i] + 3, 2);
			timeUnitStr[2] = '\0';
		} else {
			strncpy(timeUnitStr, unsortedDates[i] + 6, 4);
			timeUnitStr[4] = '\0';
		}
		int idx;
		if (strcmp(timeUnit, "year") == 0) {
			idx = startPos[atoi(timeUnitStr) - 1970];
		} else {
			idx = startPos[atoi(timeUnitStr) - 1];
		}
		sortedByTimeUnit[idx] = malloc(dateLen * sizeof(char));
		if (!sortedByTimeUnit[idx]) {
			perror("Malloc");
			return NULL;
		}
		memcpy(sortedByTimeUnit[idx], unsortedDates[i], dateLen * sizeof(char));
		if (strcmp(timeUnit, "year") == 0) {
			*(startPos + atoi(timeUnitStr) - 1970) = idx + 1;
		} else {
			*(startPos + atoi(timeUnitStr) - 1) = idx + 1;
		}
		free(unsortedDates[i]);
	}
	free(unsortedDates);
	free(startPos);
	return sortedByTimeUnit;
}

void sortDates(char fileName[], int numOfLines) {
	char **datesLines = getLines(fileName, numOfLines);
	if (!datesLines) {
		perror("Error getting dates");
		return;
	}
	char **sortedByDate = sortByTimeUnit(datesLines, numOfLines, "date");
	if (!sortedByDate) {
		perror("Error sorting by date");
		return;
	}
	char **sortedByMonth = sortByTimeUnit(sortedByDate, numOfLines, "month");
	if (!sortedByMonth) {
		perror("Error sorting by month");
		return;
	}
	char **sortedByYear = sortByTimeUnit(sortedByMonth, numOfLines, "year");
	if (!sortedByYear) {
		perror("Error sorting by year");
		return;
	}
	FILE *datesFileWrite = fopen(fileName, "w");
	if (datesFileWrite == NULL) {
		perror("Error opening file");
		return;
	}
	for (int i = 0; i < numOfLines; i++) {
		fprintf(datesFileWrite, "%s", sortedByYear[i]);
		free(sortedByYear[i]);
	}
	free(sortedByYear);
	fclose(datesFileWrite);
}

void generateDates(char fileName[], int numOfLines) {
	srand(time(NULL));
	time_t now;
	struct tm *timeinfo;
	now = time(0);
	timeinfo = localtime(&now);
	
	FILE *datesFileWrite = fopen(fileName, "w");
	if (datesFileWrite == NULL) {
		perror("Error opening file");
		return;
	}
	for (int i = 0; i < numOfLines; i++) {
		int year = rand() % (timeinfo->tm_year - 70) + 1970;
		int month = rand() % 12 + 1;
		int date;
		if (month % 2 == 0 && month >= 8 || month % 2 == 1 && month < 8) {
			date = rand() % 31 + 1;
		} else {
			if (month == 2) {
				if (year % 4 == 0 &&
					((year % 400) == 0 || (year % 100) != 0)) {
					date = rand() % 29 + 1;
				} else {
					date = rand() % 28 + 1;
				}
			} else {
				date = rand() % 30 + 1;
			}
		}
		fprintf(datesFileWrite, "%02d-%02d-%04d\n", date, month, year);
	}
	fclose(datesFileWrite);
}

int main(int argc, char *argv[]) {
	struct timeval startTime;
	struct timeval endTime;
	for (int i = 0; i < 8; i++) {
		generateDates("dates.txt", pow(10, i));
		gettimeofday(&startTime, NULL);
		sortDates("dates.txt", pow(10, i));
		gettimeofday(&endTime, NULL);
		unsigned long long startTimeUs =
			(unsigned long long)startTime.tv_sec * 1000000 + startTime.tv_usec;
		unsigned long long endTimeUs =
			(unsigned long long)endTime.tv_sec * 1000000 + endTime.tv_usec;
		printf("Number of dates: %d\n", (int)pow(10, i));
		printf("Time taken: %fs.\n", (endTimeUs - startTimeUs) / 1000000.0);
	}
}
