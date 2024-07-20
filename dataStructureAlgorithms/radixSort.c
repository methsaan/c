#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void *countingSort(int *readArr, int *writeArr, int len) {
	int freq[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int buckets[10][len];
	for (int x = 0; x < len; x++) {
		buckets[readArr[x]][freq[readArr[x]]] = writeArr[x];
		freq[readArr[x]]++;
	}
	int startingPos[10];
	for (int x = 0; x < 10; x++) {
		startingPos[x] = freq[x];
	}
	for (int x = 1; x < 10; x++) {
		startingPos[x] += startingPos[x-1];
	}
	for (int x = 9; x > 0; x--) {
		startingPos[x] = startingPos[x-1];
	}
	startingPos[0] = 0;
	for (int x = 0; x < 9; x++) {
		int cnt = 0;
		for (int y = startingPos[x]; y < startingPos[x+1]; y++) {
			readArr[y] = x;
			writeArr[y] = buckets[x][cnt++];
		}
	}
	if (startingPos[9] < len) {
		int cnt = 0;
		for (int x = startingPos[9]; x < len; x++) {
			readArr[x] = 9;
			writeArr[x] = buckets[9][cnt++];
		}
	}
}

// Radix sort (LSD) - sort array of integers
// Use counting sort to sort elements by least significant digit (one's place), preserve order of elements
// Repeat for next least significant digit, perserve order of elements from previous sort when adding elements to
// the same bucket
// Repeat until most significant digit
void *radixSort(int *arr, int l, int maxDigits) {
	int digitArr[l];
	for (int x = 0; x < maxDigits; x++) {
		for (int i = 0; i < l; i++) {
			digitArr[i] = (arr[i] % (int)pow(10, x+1) - arr[i] % (int)pow(10, x)) / (int)pow(10, x);
		}
		countingSort(digitArr, arr, l);
	}
}

int main(int argc, char* argv[]) {
	int array[] = {83, 24, 95, 42, 47, 17, 38, 65, 99, 35, 37, 86, 15, 23, 3, 26, 34, 96, 25, 34, 58, 53, 43, 94, 91, 85, 29, 36, 41, 73, 67, 54, 59, 74, 76};
	printf("Unsorted: ");
	for (int x = 0; x < sizeof(array)/sizeof(*array); x++) {
		printf("%d ", array[x]);
	}
	printf("\n");
	radixSort(array, sizeof(array)/sizeof(*array), 2);
	printf("Sorted: ");
	for (int x = 0; x < sizeof(array)/sizeof(*array); x++) {
		printf("%d ", array[x]);
	}
	printf("\n");
	// Time complexity: O(n)
}
