#include <stdio.h>

// Bubble sort - sort array
// Swap first element with rest until smallest element is at the front
// repeat for all positions until array is fully sorted
int bubbleSort(int *arr, int len) {
	int numOfOp = 0;
	for (int x = 0; x < len; x++) {
		for (int y = x; y < len; y++) {
			if (arr[x] > arr[y]) {
				int a = arr[x];
				*(arr+x) = arr[y];
				*(arr+y) = a;
			}
			numOfOp++;
		}
	}
	return numOfOp;
}

int main(int argc, char* argv[]) {
	int array[] = {83, 24, 95, 42, 47, 17, 65, 38, 99, 35, 37, 86, 15, 23, 3, 26, 34, 96, 25, 34, 58, 53, 43, 94, 91, 85, 29, 36, 41, 73, 67, 54, 59, 74, 76};
	int numOfOperations = bubbleSort(array, sizeof(array)/sizeof(*array));
	printf("Sorted: ");
	for (int x = 0; x < sizeof(array)/sizeof(*array); x++) {
		printf("%d ", array[x]);
	}
	printf("\n");
	printf("Size of data: %d, num of operations (worst-case): %d.\n", sizeof(array)/sizeof(*array), numOfOperations);
	// Size of data: 35, num of operations (worst-case): 630.
	// 35^2 / 2 = 612
	// Time complexity: O(n^2)
}
