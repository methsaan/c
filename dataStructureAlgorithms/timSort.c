#include <stdio.h>
#include <stdlib.h>

int minRun = 33;

int reverse(int *arr, int start, int end) {
	for (int x = start; (end-x+start-1) - x >= 1; x++) {
		int temp = arr[x];
		arr[x] = arr[end-x+start-1];
		arr[end-x+start-1] = temp;
	}
}

void binaryInsertionSort(int *fullArr, int start, int end, int lenSorted, int dir) {
	for (int x = start; x < end; x++) {
		if (x < start+lenSorted) {
			continue;
		} else {
			int startSorted = start;
			int endSorted = start+lenSorted;
			int idx = (startSorted + endSorted)/2;
			while ((endSorted - startSorted) > 1) {
				if ((dir == 1) ? (fullArr[x] > fullArr[idx-1] && fullArr[x] < fullArr[idx]) : (fullArr[x] < fullArr[idx-1] && fullArr[x] > fullArr[idx])) {
					break;
				} else if ((dir == 1) ? (fullArr[x] > fullArr[idx-1] && fullArr[x] > fullArr[idx]) : (fullArr[x] < fullArr[idx-1] && fullArr[x] < fullArr[idx])) {
					startSorted = idx;
				} else {
					endSorted = idx;
				}
				idx = (int)((startSorted + endSorted)/2);
			}
			if (((dir == 1) ? (fullArr[x] > fullArr[idx]) : (fullArr[x] < fullArr[idx])) && (endSorted - startSorted) <= 1) {
				idx++;
			}
			int temp = fullArr[x];
			for (int x = start+lenSorted; x > idx; x--) {
				fullArr[x] = fullArr[x-1];
			}
			fullArr[idx] = temp;
			lenSorted++;
		}
	}
}

void merge(int *fullArr, int runSize, int len) {
	for (int x = 0; x < len/runSize + 1; x += 2) {
		int cnt1 = x*runSize;
		int cnt2 = (x+1)*runSize;
		int tempArr[2*runSize];
		int i;
		for (i = x*runSize; i < (x+2)*runSize; i++) {
			if (fullArr[cnt1] <= fullArr[cnt2] && cnt1 < (x+1)*runSize && cnt2 < (x+2)*runSize && cnt2 < len) {
				tempArr[i-x*runSize] = fullArr[cnt1++];
			} else if (fullArr[cnt1] > fullArr[cnt2] && cnt1 < (x+1)*runSize && cnt2 < (x+2)*runSize && cnt2 < len) {
				tempArr[i-x*runSize] = fullArr[cnt2++];
			} else {
				break;
			}
		}
		if (cnt1 < (x+1)*runSize) {
			while (i < (x+2)*runSize && i < len) {
				tempArr[i-x*runSize] = fullArr[i];
				i++;
			}
			tempArr[i-x*runSize] = fullArr[i];
			i++;
		} else {
			while (i < (x+2)*runSize && i < len) {
				tempArr[i-x*runSize] = fullArr[i];
				i++;
			}
			tempArr[i-x*runSize] = fullArr[i];
			i++;
		}
		for (int j = x*runSize; j < (x+2)*runSize && j < len; j++) {
			fullArr[j] = tempArr[j-x*runSize];
		}
	}
	if (runSize*2 < len) {
		runSize *= 2;
		merge(fullArr, runSize, len);
	}
}

void timSort(int *arr, int len) {
	int cnt = 0;
	int direction = 0;
	int runLen = 1;
	for (int x = 1; x < len; x++) {
		if (arr[x] < arr[x-1]) {
			if (direction == 0) {
				direction = -1;
				runLen++;
			} else if (direction == -1) {
				runLen++;
			} else if (direction == 1) {
				if (runLen < minRun && (cnt+1)*minRun <= len) {
					binaryInsertionSort(arr, cnt*minRun, (cnt+1)*minRun, runLen, direction);
					cnt++;
					x = cnt*minRun;
				} else if ((cnt+1)*minRun > len) {
					binaryInsertionSort(arr, cnt*minRun, len, runLen, direction);
					cnt++;
					x = len;
				}
				runLen = 1;
				direction = 0;
			}
		} else {
			if (direction == 0) {
				direction = 1;
				runLen++;
			} else if (direction == 1) {
				runLen++;
			} else if (direction == -1) {
				if (runLen < minRun && (cnt+1)*minRun <= len) {
					binaryInsertionSort(arr, cnt*minRun, (cnt+1)*minRun, runLen, direction);
					reverse(arr, cnt*minRun, (cnt+1)*minRun);
					cnt++;
					x = cnt*minRun;
				} else if ((cnt+1)*minRun > len) {
					binaryInsertionSort(arr, cnt*minRun, len, runLen, direction);
					reverse(arr, cnt*minRun, len);
					cnt++;
					x = len;
				}
				runLen = 1;
				direction = 0;
			}
		}
	}
	merge(arr, minRun, len);
}

int main() {
	int array[] = {83, 24, 95, 42, 47, 17, 38, 65, 99, 35, 37, 86, 15, 23, 3, 26, 34, 96, 25, 34, 58, 53, 43, 94, 91, 85, 29, 36, 41, 73, 67, 54, 59, 74, 76, 62, 487, 65, 36, 58, 84, 345, 734, 312, 965, 11, 263, 66, 735, 23, 47, 273, 69, 34, 27, 75, 97, 15, 48, 345, 84, 98, 333, 374, 67, 25, 58, 43, 26, 997, 324, 236, 867, 194, 382, 338, 2654, 881, 471, 316, 716, 472, 865, 844, 235, 374, 965, 235, 685, 426, 825, 462, 347, 697, 3432, 3478, 33, 88, 263, 8568, 3252, 102, 6326, 110, 330, 773, 325, 968, 1412, 566, 324, 745, 885, 563, 886, 258, 845, 785, 443, 282, 364, 118, 265, 782, 998, 238, 976, 185, 36, 29};
	printf("Unsorted: ");
	for (int x = 0; x < sizeof(array)/sizeof(*array); x++) {
		printf("%d ", array[x]);
	}
	printf("\n\n");
	timSort(array, sizeof(array)/sizeof(*array));
	printf("Sorted: ");
	for (int x = 0; x < sizeof(array)/sizeof(*array); x++) {
		printf("%d ", array[x]);
	}
	printf("\n");
}
