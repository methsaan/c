#include <stdio.h>

// Insertion sort - sort array
// Store second value as a temporary variable if not sorted relative to first element
// Shift previous (sorted) elements until correct position is reached
// Place temporary variable in the position
// Repeat for the remaining unsorted elements
int insertionSort(int *arr, int len) {
	int numOfOp = 0;
	for (int x = 1; x < len; x++) {
		if (arr[x] > arr[x-1]) {
			continue;
		}
		int temp = arr[x];
		for (int y = x-1; y >= 0; y--) {
			if (arr[y] > temp) {
				*(arr+y+1) = arr[y];
				numOfOp++;
				if (y == 0) {
					*(arr+y) = temp;
				}
			} else {
				*(arr+y+1) = temp;
				numOfOp++;
				break;
			}
		}
	}
	return numOfOp;
}

int main(int argc, char* argv[]) {
	int array[] = {83, 24, 95, 42, 47, 17, 38, 65, 99, 35, 37, 86, 15, 23, 3, 26, 34, 96, 25, 34, 58, 53, 43, 94, 91, 85, 29, 36, 41, 73, 67, 54, 59, 74, 76};
	printf("Unsorted: ");
	for (int x = 0; x < sizeof(array)/sizeof(*array); x++) {
		printf("%d ", array[x]);
	}
	printf("\n");
	int numOfOperations = insertionSort(array, sizeof(array)/sizeof(*array));
	printf("Sorted: ");
	for (int x = 0; x < sizeof(array)/sizeof(*array); x++) {
		printf("%d ", array[x]);
	}
	printf("\n");
	printf("Size of data: %d, num of operations (worst case): %d.\n", sizeof(array)/sizeof(*array), numOfOperations);
	// Size of data: 35, num of operations: 283.
	// Size of data: 35, num of operations (worst case): 595.
	// Time complexity: O(n^2)
}
