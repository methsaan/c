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
/*
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
					cnt++;
					x = cnt*minRun;
				}
				runLen = 1;
				direction = 0;
			}
		}
	}
}
*/
int main() {
	int array[] = {83, 24, 95, 42, 47, 17, 38, 65, 99, 35, 37, 86, 15, 23, 3, 26, 34, 96, 25, 34, 58, 53, 43, 94, 91, 85, 29, 36, 41, 73, 67, 54, 59, 74, 76, 62, 487, 65, 36, 58, 84, 345, 734, 312, 965, 11, 263, 66, 735, 23, 47, 273, 69, 34, 27, 75, 97, 15, 48, 345, 84, 98, 333, 374, 67, 25, 58, 43, 26, 997, 324, 236, 867, 194, 382, 338, 2654, 881, 471, 316, 716, 472, 865, 844, 235, 374, 965, 235, 685, 426, 825, 462, 347, 697, 3432, 3478, 33, 88, 263, 8568, 3252, 102, 6326, 110, 330, 773, 325, 968, 1412, 566, 324, 745, 885, 563, 886, 258, 845, 785, 443, 282, 364, 118, 265, 782, 998, 238, 976, 185, 36, 29};
	printf("Unsorted: ");
	for (int x = 0; x < sizeof(array)/sizeof(*array); x++) {
		printf("%d ", array[x]);
	}
	printf("\n");
	//timSort(array, sizeof(array)/sizeof(*array));
        //reverse(array, 8, 17);
	//timSort(array, sizeof(array)/sizeof(*array));
	printf("Sorted: ");
	for (int x = 0; x < sizeof(array)/sizeof(*array); x++) {
		printf("%d ", array[x]);
	}
	printf("\n");
	binaryInsertionSort(array, 0, sizeof(array)/sizeof(*array)-10, 1, -1);
	printf("Sorted: ");
	for (int x = 0; x < sizeof(array)/sizeof(*array); x++) {
		printf("%d ", array[x]);
	}
	printf("\n");
}
