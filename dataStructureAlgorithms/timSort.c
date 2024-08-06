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
	//printf("\n\nNEW MERGE\n------------------------------------------------------\n");
	//printf("len/runSize + 1: %d\n", len/runSize + 1);
	//printf("runSize: %d\n", runSize);
	for (int x = 0; x < len/runSize + 1; x += 2) {
		printf("x: %d\n", x);
		printf("x: %d, len/runSize + 1: %d\n", x, len/runSize + 1);
		int cnt1 = x*runSize;
		int cnt2 = (x+1)*runSize;
		int tempArr[2*runSize];
		//printf("cnt1 - x*runSize: %d\n", x*runSize);
		//printf("cnt2 - (x+1)*runSize: %d\n", (x+1)*runSize);
		//printf("Size of tempArr - 2*runSize: %d\n", 2*runSize);
		int i;
		//printf("ITERATING %d-%d\n", x*runSize, (x+2)*runSize-1);
		//printf("ELEMENTS: ");
		//for (int y = x*runSize; y < (x+2)*runSize; y++) {
		//	printf("%d ", fullArr[y]);
		//}
		//printf("\n");
		for (i = x*runSize; i < (x+2)*runSize; i++) {
			if (fullArr[cnt1] <= fullArr[cnt2] && cnt1 < (x+1)*runSize && cnt2 < (x+2)*runSize && cnt2 < len) {
				//printf("TRUE: fullArr[cnt1] (%d) <= fullArr[cnt2] (%d) && cnt2 (%d) < (x+2)*runSize (%d) && cnt2 (%d) < len (%d)\n", fullArr[cnt1], fullArr[cnt2], cnt2, (x+2)*runSize, cnt2, len);
				//printf("%d, cnt1: %d\n", fullArr[cnt1], cnt1+1);
				tempArr[i-x*runSize] = fullArr[cnt1++];
			} else if (fullArr[cnt1] > fullArr[cnt2] && cnt1 < (x+1)*runSize && cnt2 < (x+2)*runSize && cnt2 < len) {
				//printf("%d, cnt2: %d\n", fullArr[cnt2], cnt2+1-(x+1)*runSize);
				tempArr[i-x*runSize] = fullArr[cnt2++];
			} else {
				break;
			}
		}
		//printf("STARTING AT ARRAY INDEX %d: ", x*runSize);
		//for (int j = 0; j < (x+2)*runSize; j++) {
		//	printf("%d ", tempArr[j]);
		//}
		//printf("\n\n");
		//printf("cnt1-x*runSize (%d) + cnt2-(x+1)*runSize (%d): %d\n", cnt1-x*runSize, cnt2-(x+1)*runSize, cnt1-x*runSize + cnt2-(x+1)*runSize);
		//printf("i: %d\n", i);
		//printf("tempArr[i-x*runSize-1]: %d\n", tempArr[i-x*runSize-1]);
		printf("x: %d, len/runSize + 1: %d\n", x, len/runSize + 1);
		printf("len: %d, runSize: %d\n", len, runSize);
		if (cnt1 < (x+1)*runSize) {
			while (i < (x+2)*runSize && i < len) {
				tempArr[i-x*runSize] = fullArr[i];
				i++;
			}
			tempArr[i-x*runSize] = fullArr[i++];
			//printf("ADDING REST OF FIRST HALF...\n\n");
		} else {
			printf("x: %d, len/runSize + 1: %d\n", x, len/runSize + 1);
			printf("len: %d, runSize: %d\n", len, runSize);
			while (i < (x+2)*runSize && i < len) {
				tempArr[i-x*runSize] = fullArr[i];
				i++;
			}
			printf("---x: %d, len/runSize + 1: %d\n", x, len/runSize + 1);
			printf("---len: %d, runSize: %d\n", len, runSize);
			tempArr[i-x*runSize] = fullArr[i++];
			len = 130;
			printf("---x: %d, len/runSize + 1: %d\n", x, len/runSize + 1);
			printf("---len: %d, runSize: %d\n", len, runSize);
			//printf("ADDING REST OF SECOND HALF...\n\n");
		}
		printf("x: %d, len/runSize + 1: %d\n", x, len/runSize + 1);
		printf("len: %d, runSize: %d\n", len, runSize);
		for (int j = x*runSize; j < (x+2)*runSize; j++) {
			fullArr[j] = tempArr[j-x*runSize];
		}
		printf("x: %d, len/runSize + 1: %d\n", x, len/runSize + 1);
		//printf("STARTING AT ARRAY INDEX %d: ", x*runSize);
		//for (int j = 0; j < (x+2)*runSize; j++) {
		//	printf("%d ", tempArr[j]);
		//}
		//printf("\n\n");
		printf("x: %d, len/runSize + 1: %d\n", x, len/runSize + 1);
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
				if (runLen < minRun) {
					binaryInsertionSort(arr, cnt*minRun, (cnt+1)*minRun, runLen, direction);
					cnt++;
					x = cnt*minRun;
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
				if (runLen < minRun) {
					binaryInsertionSort(arr, cnt*minRun, (cnt+1)*minRun, runLen, direction);
					reverse(arr, cnt*minRun, (cnt+1)*minRun);
					cnt++;
					x = cnt*minRun;
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
	printf("\n");
	timSort(array, sizeof(array)/sizeof(*array));
        //reverse(array, 8, 17);
	//timSort(array, sizeof(array)/sizeof(*array));
	printf("\n\n");
	printf("Sorted: ");
	for (int x = 0; x < sizeof(array)/sizeof(*array); x++) {
		printf("%d ", array[x]);
	}
	printf("\n");
}
