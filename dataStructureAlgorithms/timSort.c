#include <stdio.h>
#include <stdlib.h>

int minRun = 4;

int reverse(int *arr, int start, int end) {
	for (int x = start; (end-x+start-1) - x >= 1; x++) {
		int temp = arr[x];
		arr[x] = arr[end-x+start-1];
		arr[end-x+start-1] = temp;
	}
}

int* runs(int *arr, int len, int *numOfRuns) {
	int *runs = malloc(len*sizeof(int));
	runs[0] = 0;
	int cnt = 1;
	int direction = 0;
	int runLen = 1;
	for (int x = 1; x < len; x++) {
		if (arr[x] < arr[x-1]) {
			if (direction == 0) {
				direction = -1;
				runLen++;
			} else if (direction == -1) {
				runLen++;
			} else {
				runs[cnt++] = runs[cnt-1]+runLen;
				runLen = 1;
				direction = 0;
			}
		} else {
			if (direction == 0) {
				direction = 1;
				runLen++;
			} else if (direction == 1) {
				runLen++;
			} else {
				runs[cnt++] = runs[cnt-1]+runLen;
				runLen = 1;
				direction = 0;
			}
		}
	}
	runs[cnt++] = len;
	*numOfRuns = cnt;
	return runs;
}

//int timSort(int *arr, int len) {
//}

int main() {
	// 0, 2, 4, 6, 9, 12, 14, 18, 21, 23, 27, 30, 32, 35
	int array[] = {83, 24, 95, 42, 47, 17, 38, 65, 99, 35, 37, 86, 15, 23, 3, 26, 34, 96, 25, 34, 58, 53, 43, 94, 91, 85, 29, 36, 41, 73, 67, 54, 59, 74, 76};
	printf("Unsorted: ");
	for (int x = 0; x < sizeof(array)/sizeof(*array); x++) {
		printf("%d ", array[x]);
	}
	printf("\n");
	int runsCnt;
	int* runArr = runs(array, sizeof(array)/sizeof(*array), &runsCnt);
	printf("runArr: ");
	for (int x = 0; x < runsCnt; x++) {
		printf("%d ", runArr[x]);
	}
	printf("\n");
	printf("runsCnt: %d\n", runsCnt);
	printf("Unsorted: ");
	for (int x = 0; x < runsCnt-1; x++) {
		for (int y = runArr[x]; y < runArr[x+1]-1; y++) {
			printf("%d ", array[y]);
		}
		printf("%d", array[runArr[x+1]-1]);
		printf("|");
	}
	printf("\n");
        //reverse(array, 8, 17);
	//timSort(array, sizeof(array)/sizeof(*array));
	printf("Sorted: ");
	for (int x = 0; x < sizeof(array)/sizeof(*array); x++) {
		printf("%d ", array[x]);
	}
	printf("\n");
}
