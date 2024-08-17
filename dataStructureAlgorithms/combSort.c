#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double shrinkFactor = 1.3;

// Comb Sort - sort array
// Initialize gap size as length of array.
// Loop through array, comparing each element with element gap size away
// and swapping if out of order, until the end of the array is reached.
// Decrease gap size by a factor of 1.3 and repeat until gap size is 1
void combSort(int *arr, int len) {
	int gapSize = len;
	while (gapSize >= 1) {
		for (int x = 0; x < len && x + gapSize < len; x++) {
			if (arr[x] > arr[x+gapSize]) {
				int temp = arr[x];
				arr[x] = arr[x+gapSize];
				arr[x+gapSize] = temp;
			}
		}
		gapSize = (int)((double)gapSize/shrinkFactor);
	}
}

int main(int argc, char* argv[]) {
	int array[] = {83, 24, 95, 42, 47, 17, 38, 65, 99, 35, 37, 86, 15, 23, 3, 26, 34, 96, 25, 34, 58, 53, 43, 94, 91, 85, 29, 36, 41, 73, 67, 54, 59, 74, 76};
	printf("Unsorted: ");
	for (int x = 0; x < sizeof(array)/sizeof(*array); x++) {
		printf("%d ", array[x]);
	}
	printf("\n");
	combSort(array, sizeof(array)/sizeof(*array));
	printf("Sorted: ");
	for (int x = 0; x < sizeof(array)/sizeof(*array); x++) {
		printf("%d ", array[x]);
	}
	printf("\n");
}
