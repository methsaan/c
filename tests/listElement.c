#include <stdio.h>

int isIn(int *arr, int element, int length) {
	for (int x = 0; x < length; x++) {
		if (arr[x] == element) {
			return 1;
		}
	}
	return 0;
}

int main(int argc, char *argv) {
	int ones[] = {10, 5, 6, 8};
	for (int x = 0; x < 10; x++) {
		printf("x: %d\n", x);
		if (isIn(ones, x, 4)) {
			printf("In\n");
		}
	}
}
