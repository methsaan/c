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
	double side1;
	double height;
	double side2;
	double side3;
	double d;
	side1 = sqrt(pow(abs(x2-x1), 2)+pow(abs(y2-y1), 2));
	side2 = sqrt(pow(abs(x3-x1), 2)+pow(abs(y3-y1), 2));
	side3 = sqrt(pow(abs(x3-x2), 2)+pow(abs(y3-y2), 2));
	printf("%f, %f\n", y1, x2);
}
