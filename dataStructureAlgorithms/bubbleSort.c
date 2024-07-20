#include <stdio.h>

// Bubble sort - sort array
// Swap adjacent elements until largest element is at the end
// repeat for remaining unsorted positions until array is sorted
int bubbleSort(int *arr, int len) {
	int numOfOp = 0;
	for (int x = 0; x < len; x++) {
		for (int y = 0; y < len-1-x; y++) {
			if (arr[y+1] < arr[y]) {
				int a = arr[y];
				*(arr+y) = arr[y+1];
				*(arr+y+1) = a;
			}
			numOfOp++;
		}
	}
	return numOfOp;
}

int main(int argc, char* argv[]) {
	int array[] = {83, 24, 95, 42, 47, 17, 65, 38, 99, 35, 37, 86, 15, 23, 3, 26, 34, 96, 25, 34, 58, 53, 43, 94, 91, 85, 29, 36, 41, 73, 67, 54, 59, 74, 76};
	printf("Unsorted: ");
	for (int x = 0; x < sizeof(array)/sizeof(*array); x++) {
		printf("%d ", array[x]);
	}
	printf("\n");
	int numOfOperations = bubbleSort(array, sizeof(array)/sizeof(*array));
	printf("Sorted: ");
	for (int x = 0; x < sizeof(array)/sizeof(*array); x++) {
		printf("%d ", array[x]);
	}
	printf("\n");
	printf("Size of data: %d, num of operations (worst-case): %d.\n", sizeof(array)/sizeof(*array), numOfOperations);
	// Size of data: 35, num of operations (worst-case): 595.
	// 35^2 / 2 = 612
	// Time complexity: O(n^2)
}
