#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct coord {
	int x;
	int y;
};

void convertToComputer(int *x, int *y) {
	*x += 30;
	*x *= 2;
	*y = -(*y);
	*y += 30;
}

int main(int argc, char *argv) {
	struct coord coords[30];
	for (int x = -15; x < 15; x++) {
		int y = pow(x, 2)/14+10;
		coords[x+15].x = x;
		coords[x+15].y = y;
		convertToComputer(&coords[x+15].x, &coords[x+15].y);
	}
	for (int i = 0; i < 30; i++) {
		system("clear");
		printf("(%d, %d)\n", coords[i].x/2-30, -(coords[i].y-30));
		for (int j = 0; j < coords[i].y-2; j++) {
			printf("\n");
		}
		for (int j = 0; j < coords[i].x-1; j++) {
			printf(" ");
		}
		printf("X\n");
		for (long int j = 0; j < 900000; j++) {
			;
		}
	}
}
