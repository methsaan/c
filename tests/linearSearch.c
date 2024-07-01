#include <stdio.h>

int linearSearch(int *arr, int target, int len, int tshow) {
	int numOfOperations = 0;
	for (int x = 0; x < len; x++) {
		numOfOperations++;
		if (arr[x] == target) {
			if (tshow) {
				printf("Size of data: %d, num of operations (worst-case): %d.\n", len, numOfOperations);
			}
			return x;
		}
	}
	if (tshow) {
		printf("Size of data: %d, num of operations (worst-case): %d.\n", len, numOfOperations);
	}
	return -1;
}

int main(int argc, char* argv[]) {
	int array[] = {5, 2, 7, 15, 31, 98, 26, 59, 44};
	int num = 31;
	int idx = linearSearch(array, num, sizeof(array)/sizeof(*array), 0);
	if (idx == -1) {
		printf("Value not found.\n");
	} else {
		printf("%d found at index %d.\n", num, idx);
	}
	num = 44;
	idx = linearSearch(array, num, sizeof(array)/sizeof(*array), 1);
}
