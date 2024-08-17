#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double shrinkFactor = 2.3;

// Shell Sort - sort array
// Initialize gap size as length of array.
// Loop through array (incrementing by gap size), compare current element
// to element from previous iterations and move the checked element to
// its index + gap size if out of order
// Place current element after the k-sorted portion if in order
// Decrease gap size by a factor of 2.3 and repeat until gap size is 1
void shellSort(int *arr, int len) {
	int k = len;
	while (k >= 1) {
		for (int x = k; x < len; x += k) {
			int temp = arr[x];
			int y;
			for (y = x-k; y >= 0; y -= k) {
				if (temp < arr[y]) {
					arr[y+k] = arr[y];
				} else {
					break;
				}
			}
			arr[y+k] = temp;
		}
		if (k == 2) {
			k = 1;
		} else {
			k = (int)((double)k/shrinkFactor);
		}
	}
}

int main(int argc, char* argv[]) {
	int array[] = {83, 24, 95, 42, 47, 17, 38, 65, 99, 35, 37, 86, 15, 23, 3, 26, 34, 96, 25, 34, 58, 53, 43, 94, 91, 85, 29, 36, 41, 73, 67, 54, 59, 74, 76};
	printf("Unsorted: ");
	for (int x = 0; x < sizeof(array)/sizeof(*array); x++) {
		printf("%d ", array[x]);
	}
	printf("\n");
	shellSort(array, sizeof(array)/sizeof(*array));
	printf("Sorted: ");
	for (int x = 0; x < sizeof(array)/sizeof(*array); x++) {
		printf("%d ", array[x]);
	}
	printf("\n");
}
