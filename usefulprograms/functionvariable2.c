#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	system("clear");
	for (int x = 0; x < 40; x++) {
		int y = pow(x, 10)/2
;
		if (y < 46 && y > 0 && x < 46) {
			printf("\033[%d;%dHx", y, 46-x);
		}
	}
}