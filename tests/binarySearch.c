#include <stdio.h>

// Binary search - search for element in sorted array
// Set start to beginning index of array and end to last index of array
// Check if middle index is equal to target
// If target is lower, set end to middle
// If target is higher, set start to middle
// Repeat until middle is equal to target
int binarySearch(int *arr, int target, int len, int tshow) {
	int numOfOperations = 0;
	int start = 0;
	int end = len;
	int mid = (int)(len/2);
	while ((end - start) > 1) {
		if (target == arr[mid]) {
			if (tshow) {
				printf("Size of data: %d, num of operations (worst-case): %d.\n", len, numOfOperations);
			}
			return mid;
		} else if (target > arr[mid]) {
			start = mid;
		} else {
			end = mid;
		}
		mid = (int)((start + end)/2);
		numOfOperations += 1;
	}
	if (tshow) {
		printf("Size of data: %d, num of operations (worst-case): %d.\n", len, numOfOperations);
	}
	return -1;
}

int main(int argc, char* argv[]) {
	int array[] = {3, 4, 6, 15, 18, 27, 34, 48, 53, 58, 67, 74, 96, 100, 140, 176, 213, 270, 376, 467, 679, 1025};
	int num = 270;
	int idx = binarySearch(array, num, sizeof(array)/sizeof(*array), 0);
	if (idx == -1) {
		printf("Value not found.\n");
	} else {
		printf("%d found at index %d.\n", num, idx);
	}
	num = 3000;
	idx = binarySearch(array, num, sizeof(array)/sizeof(*array), 1);
	// Size of data: 22, num of operations (worst-case): 5. 
	// log2(22) = 4.45
	// Time complexity: O(n) = log2(n)
}
