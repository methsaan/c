#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct coord {
	int x;
	int y;
};

void convertToComputer(int *x, int *y) {
	*x += 10;
	*x *= 2;
	*y = -(*y);
	*y += 10;
}

int main(int argc, char *argv) {
	struct coord coords[10];
	for (int x = -5; x < 5; x++) {
		int y;
		printf("%d %d\n", x, y);
	}
	for (int i = 0; i < 10; i++) {
		for (long int j = 0; j < 30000000; j++) {
			;
		}
	}
}
