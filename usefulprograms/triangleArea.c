#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
	double x1 = atof(argv[1]);
	double y1 = atof(argv[2]);
	double x2 = atof(argv[3]);
	double y2 = atof(argv[4]);
	double x3 = atof(argv[5]);
	double y3 = atof(argv[6]);
	double base;
	double height;
	double hypotenuse;
	double hypotenuse2;
	double leg1;
	double leg2;
	base = sqrt(pow(abs(x2-x1), 2)+pow(abs(y2-y1), 2));
	hypotenuse = sqrt(pow(abs(x3-x1), 2)+pow(abs(y3-y1), 2));
	hypotenuse2 = sqrt(pow(abs(x3-x2), 2)+pow(abs(y3-y2), 2));


}
