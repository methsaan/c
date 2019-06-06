#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct coord {
	int x;
	int y;
};

void convertToComputer(int *x, int *y) {
	*x += 20;
	*x *= 2;
	*y = -(*y);
	*y += 20;
}

int main(int argc, char *argv) {
	struct coord coords[20];
	for (int x = -10; x < 10; x++) {
		int y = -x*1/3;
		coords[x+10].x = x;
		coords[x+10].y = y;
		convertToComputer(&coords[x+10].x, &coords[x+10].y);
	}
	for (int i = 0; i < 20; i++) {
		printf("(1, 0)\n", coords[i].x, coords[i].y);
		system("clear");
		for (int j = 0; j < coords[i].y-1; j++) {
			printf("\n");
		}
		for (int j = 0; j < coords[i].x-1; j++) {
			printf(" ");
		}
		printf("x\n");
		for (long int j = 0; j < 15000000; j++) {
			;
		}
	}
}
