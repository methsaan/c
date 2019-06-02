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
		coords[x+5].x = x;
		coords[x+5].y = y;
		convertToComputer(&coords[x+5].x, &coords[x+5].y);
	}
	for (int i = 0; i < 10; i++) {
		printf("(1, 0)\n", coords[i].x, coords[i].y);
		for (long int j = 0; j < 30000000; j++) {
			;
		}
	}
}
