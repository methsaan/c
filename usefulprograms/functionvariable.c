#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct coord {
	int x;
	int y;
};

void convertToComputer(int *x, int *y) {
	*x += 40;
	*x *= 2;
	*y = -(*y);
	*y += 40;
}

int main(int argc, char *argv) {
	struct coord coords[40];
	for (int x = -20; x < 20; x++) {
		int y = -x;
		coords[x+20].x = x;
		coords[x+20].y = y;
		convertToComputer(&coords[x+20].x, &coords[x+20].y);
	}
	for (int i = 0; i < 40; i++) {
		system("clear");
		printf("(%d, %d)\n", coords[i].x/2-40, -(coords[i].y-40));
		for (int j = 0; j < coords[i].y-10; j++) {
			printf("\n");
		}
		for (int j = 0; j < coords[i].x-1; j++) {
			printf(" ");
		}
		printf("X\n");
		for (long int j = 0; j < 4000000; j++) {
			;
		}
	}
}
