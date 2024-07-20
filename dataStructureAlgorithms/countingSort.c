#include <stdio.h>
#include <stdlib.h>

// Counting sort - sort array with small range
// Store frequency of all values within range in the array
// Use frequencies to determine starting position of each value
// within range (highest value with same starting position overrides lower values)
// rewrite array by filling in all values within range at their respective starting values
void *countingSort(int *arr, int len) {
	int freq[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	for (int x = 0; x < len; x++) {
		freq[arr[x]]++;
	}
	for (int x = 1; x < 10; x++) {
		freq[x] += freq[x-1];
	}
	for (int x = 9; x > 0; x--) {
		freq[x] = freq[x-1];
	}
	freq[0] = 0;
	for (int x = 0; x < 9; x++) {
		for (int y = freq[x]; y < freq[x+1]; y++) {
			arr[y] = x;
		}
	}
	if (freq[9] < len) {
		for (int x = freq[9]; x < len; x++) {
			arr[x] = 9;
		}
	}
}

int main(int argc, char* argv[]) {
	int array[] = {2, 7, 4, 6, 0, 4, 6, 7, 2, 8, 4, 9, 4, 8, 4, 7, 9, 3, 4, 7, 2, 1, 4, 7, 4, 8, 4};
	printf("Unsorted: ");
	for (int x = 0; x < sizeof(array)/sizeof(*array); x++) {
		printf("%d ", array[x]);
	}
	printf("\n");
	countingSort(array, sizeof(array)/sizeof(*array));
	printf("Sorted: ");
	for (int x = 0; x < sizeof(array)/sizeof(*array); x++) {
		printf("%d ", array[x]);
	}
	printf("\n");
	// Time complexity: O(n)
}
