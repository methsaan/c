#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Circle Sort - sort array
// Swap elements that are the same distance from the middle index if they are
// out of order
// Split array and repeat recursively until subarrays have length 2
// Repeat algorithm starting from full array until no swaps are made in a full round
void circleSort(int *arr, int start, int end, int *swapCnt, int startFull, int endFull, int arrLen) {
	for (int x = start; x < (start+end+1)/2; x++) {
		if (arr[x] > arr[end-x+start] && end-x+start < arrLen) {
			int temp = arr[x];
			arr[x] = arr[end-x+start];
			arr[end-x+start] = temp;
			*swapCnt += 1;
		}
	}
	if (end-start >= 2) {
		circleSort(arr, start, (start+end+1)/2-1, swapCnt, startFull, endFull, arrLen);
		circleSort(arr, (start+end+1)/2, end, swapCnt, startFull, endFull, arrLen);
	}
	if (*swapCnt > 0 && endFull == end) {
		*(swapCnt) = 0;
		circleSort(arr, startFull, endFull, swapCnt, startFull, endFull, arrLen);
	}
}

int main(int argc, char* argv[]) {
	int array[] = {83, 24, 95, 42, 47, 17, 38, 65, 99, 35, 37, 86, 15, 23, 3, 26, 34, 96, 25, 34, 58, 53, 43, 94, 91, 85, 29, 36, 41, 73, 67, 54, 59, 74, 76};
	printf("Unsorted: ");
	for (int x = 0; x < sizeof(array)/sizeof(*array); x++) {
		printf("%d ", array[x]);
	}
	printf("\n");
	int numOfSwaps = 0;
	int len = sizeof(array)/sizeof(*array);
	circleSort(array, 0, pow(2, (int)(log(len)/log(2))+1)-1, &numOfSwaps, 0, pow(2, (int)(log(len)/log(2))+1)-1, len);
	printf("Sorted: ");
	for (int x = 0; x < sizeof(array)/sizeof(*array); x++) {
		printf("%d ", array[x]);
	}
	printf("\n");
}
