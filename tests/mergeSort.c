#include <stdio.h>
#include <stdlib.h>

int opCnt = 0;

void *merge(int *arr, int startArr1, int endArr1, int startArr2, int endArr2) {
	int cnt = 0;
	int cnt2 = 0;
	int tempArr[endArr2-startArr1+1];
	for (int x = 0; x < endArr2-startArr1+1; x++) {
		if ((arr[startArr1+cnt] >= arr[startArr2+cnt2]) && (cnt2 <= endArr2-startArr2)) {
			tempArr[x] = arr[startArr2+cnt2];
			cnt2++;
		} else if ((arr[startArr2+cnt2] >= arr[startArr1+cnt]) && (cnt <= endArr1-startArr1)) {
			tempArr[x] = arr[startArr1+cnt];
			cnt++;
		} else if ((cnt2 > endArr2-startArr2) && (cnt <= endArr1-startArr1)) {
			tempArr[x] = arr[startArr1+cnt];
			cnt++;
		} else if ((cnt2 <= endArr2-startArr2) && (cnt > endArr1-startArr1)) {
			tempArr[x] = arr[startArr2+cnt2];
			cnt2++;
		}
		opCnt++;
	}
	if (cnt == endArr1-startArr1) {
		tempArr[endArr2-startArr1] = arr[startArr1+cnt];
	} else if (cnt2 == endArr2-startArr2) {
		tempArr[endArr2-startArr1] = arr[startArr2+cnt2];
	}
	for (int x = 0; x < endArr2-startArr1+1; x++) {
		*(arr+startArr1+x) = tempArr[x];
	}
}

// Merge sort - sort array
// Split array into two at middle index
// Repeat splitting until all elements are in a single-element array
// Merge single-element array with other single-element array from same parent
// by sorting (loop through two arrays sequentially and compare adjacent elements
// since both arrays are in order)
// Repeat merge for all arrays from same parent until original array is in order
void *mergeSort(int *arr, int start, int end) {
	int mid = (start + end)/2;
	if (mid-start >= 1 && end-mid-1 >= 1) {
		mergeSort(arr, start, mid);
		mergeSort(arr, mid+1, end);
		merge(arr, start, mid, mid+1, end);
	} else if (mid-start < 1 && end-mid-1 >= 1) {
		mergeSort(arr, mid+1, end);
		merge(arr, start, mid, mid+1, end);
	} else if (end-mid-1 < 1 && mid-start >= 1) {
		mergeSort(arr, start, mid);
		merge(arr, start, mid, mid+1, end);
	} else {
		merge(arr, start, mid, mid+1, end);
	}
}

int main(int argc, char* argv[]) {
	int array[] = {83, 24, 95, 42, 47, 17, 38, 65, 99, 35, 37, 86, 15, 23, 3, 26, 34, 96, 25, 34, 58, 53, 43, 94, 91, 85, 29, 36, 41, 73, 67, 54, 59, 74, 76};
	printf("Unsorted: ");
	for (int x = 0; x < sizeof(array)/sizeof(*array); x++) {
		printf("%d ", array[x]);
	}
	printf("\n");
	mergeSort(array, 0, sizeof(array)/sizeof(*array)-1);
	printf("Sorted: ");
	for (int x = 0; x < sizeof(array)/sizeof(*array); x++) {
		printf("%d ", array[x]);
	}
	printf("\n");
	printf("Size of data: %d, number of operations: %d.\n", sizeof(array)/sizeof(*array), opCnt);
	// Size of data: 35, number of operations: 181.
	// Time complexity: O(nlog(n))
}
