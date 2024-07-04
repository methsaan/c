#include <stdio.h>
#include <stdlib.h>


int *mergeArrays(int *a, int len1, int *b, int len2) {
	int *merged = malloc(600);
	for (int x = 0; x < len1+len2; x++) {
		if (x < len1) {
			merged[x] = a[x];
		} else {
			merged[x] = b[x-len1];
		}
	}
	return merged;
}

// Quick sort - sort array
// Set a pivot value within range of the list values (average of first and last element)
// Swap elements until all numbers less the pivot value are on the left side
// and all numbers greater are on the right side of the list
// Treat elements past the pivot value index and before the pivot value index as
// two separate sublists and repeat until all sublists contain 1 element
// Recombine 1 element sublists with opposite side of sublist from parent list
// until original list is in order
int *quickSort(int *arr, int len, int z) {
	int pivot = (arr[0] + arr[len-1]) / 2;
	int i = -1;
	for (int x = 0; x < len; x++) {
		if (arr[x] <= pivot) {
			i++;
			int temp = arr[i];
			*(arr+i) = arr[x];
			*(arr+x) = temp;
		}
	}
	if (i == -1) {
		i++;
	} else if (i == len-1) {
		i--;
	} else {
		;
	}
	int arrLeft[i+1];
	int arrRight[len-i-1];
	int arrLeftSize = i+1;
	int arrRightSize = len-i-1;
	for (int x = 0; x < arrLeftSize; x++) {
		arrLeft[x] = arr[x];
	}
	for (int x = arrLeftSize; x < len; x++) {
		arrRight[x-arrLeftSize] = arr[x];
	}
	int *mergeArr;
	if ((arrLeftSize <= 1) && (arrRightSize <= 1)) {
		mergeArr = mergeArrays(arrLeft, arrLeftSize, arrRight, arrRightSize);
		return mergeArr;
	} else if (arrLeftSize <= 1) {
		mergeArr = mergeArrays(arrLeft, arrLeftSize, quickSort(arrRight, arrRightSize, z), arrRightSize);
		return mergeArr;
	} else if (arrRightSize <= 1) {
		mergeArr = mergeArrays(quickSort(arrLeft, arrLeftSize, z), arrLeftSize, arrRight, arrRightSize);
		return mergeArr;
	} else {
		mergeArr = mergeArrays(quickSort(arrLeft, arrLeftSize, z), arrLeftSize, quickSort(arrRight, arrRightSize, z), arrRightSize);
		return mergeArr;
	}
}

int main(int argc, char* argv[]) {
	int array[] = {83, 24, 95, 42, 47, 17, 38, 65, 99, 35, 37, 86, 15, 23, 3, 26, 34, 96, 25, 34, 58, 53, 43, 94, 91, 85, 29, 36, 41, 73, 67, 54, 59, 74, 76};
	printf("Unsorted: ");
	for (int x = 0; x < sizeof(array)/sizeof(*array); x++) {
		printf("%d ", array[x]);
	}
	printf("\n");
	int *sorted = quickSort(array, sizeof(array)/sizeof(*array), 0);
	printf("Sorted: ");
	for (int x = 0; x < sizeof(array)/sizeof(*array); x++) {
		printf("%d ", sorted[x]);
	}
	printf("\n");
	// Time complexity: O(nlog(n))
}
