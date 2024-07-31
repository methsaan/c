#include <stdio.h>

int minRun = 4;

int reverse(int *arr, int start, int end) {
	for (int x = start; (end-x+start-1) - x >= 1; x++) {
		int temp = arr[x];
		arr[x] = arr[end-x+start-1];
		arr[end-x+start-1] = temp;
	}
}

//int timSort(int *arr, int len) {
//}

int main() {
	int array[] = {83, 24, 95, 42, 47, 17, 38, 65, 99, 35, 37, 86, 15, 23, 3, 26, 34, 96, 25, 34, 58, 53, 43, 94, 91, 85, 29, 36, 41, 73, 67, 54, 59, 74, 76};
	printf("Unsorted: ");
	for (int x = 0; x < sizeof(array)/sizeof(*array); x++) {
		printf("%d ", array[x]);
	}
	printf("\n");
        reverse(array, 8, 17);
	//timSort(array, sizeof(array)/sizeof(*array));
	printf("Unsorted: ");
	for (int x = 0; x < sizeof(array)/sizeof(*array); x++) {
		printf("%d ", array[x]);
	}
	printf("\n");
}
