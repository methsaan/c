#include <stdio.h>

// Binary search - search for element in sorted array
// Set start to beginning index of array and end to last index of array
// Check if middle index is equal to target
// If target is lower, set end to middle
// If target is higher, set start to middle
// Repeat until middle is equal to target
int binarySearch(int *arr, int target, int len, int oglen, int tshow, int start, int end, int numOfOp) {
	int mid = (int)((start + end)/2);
	if ((end - start) == 1) {
		if (tshow) {
			printf("Size of data: %d, num of operations (worst-case): %d.\n", oglen, numOfOp); 
		}
		return -1;
	} else if (arr[mid] == target) {
		if (tshow) {
			printf("Size of data: %d, num of operations (worst-case): %d.\n", oglen, numOfOp); 
		}
		return mid;
	} else if (arr[mid] > target) {
		return binarySearch(arr, target, end-mid, oglen, tshow, start, mid, numOfOp+1);
	} else {
		return binarySearch(arr, target, mid-start, oglen, tshow, mid, end, numOfOp+1);
	}
}

int main(int argc, char* argv[]) {
	int array[] = {3, 4, 6, 15, 18, 27, 34, 48, 53, 58, 67, 74, 96, 100, 140, 176, 213, 270, 376, 467, 679, 1025};
	int num = 270;
	int idx = binarySearch(array, num, sizeof(array)/sizeof(*array), sizeof(array)/sizeof(*array), 0, 0, sizeof(array)/sizeof(*array)-1, 0);
	if (idx == -1) {
		printf("Value not found.\n");
	} else {
		printf("%d found at index %d.\n", num, idx);
	}
	num = 3000;
	idx = binarySearch(array, num, sizeof(array)/sizeof(*array), sizeof(array)/sizeof(*array), 1, 0, sizeof(array)/sizeof(*array)-1, 0);
	// Size of data: 22, num of operations (worst-case): 5. 
	// log2(22) = 4.45
	// Time complexity: O(log2(n))
}
