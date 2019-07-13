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
	double side2;
	double side3;
	double semiperimeter; 
	double area;
	side1 = sqrt(pow(abs(x2-x1), 2)+pow(abs(y2-y1), 2));
	side2 = sqrt(pow(abs(x3-x1), 2)+pow(abs(y3-y1), 2));
	side3 = sqrt(pow(abs(x3-x2), 2)+pow(abs(y3-y2), 2));
	semiperimeter = (side1+side2+side3)/2;
	area = sqrt(semiperimeter*(semiperimeter-side1)*(semiperimeter-side2)*(semiperimeter-side3));
	printf("%g\n", area);

}
