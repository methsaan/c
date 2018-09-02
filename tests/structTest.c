#include<stdio.h>
#include<math.h>

struct Square {
	int x;
	int y;
	int area;
	int per;
	double hyp;
};
int main(int argc, char* argv){
	struct Square square;
	scanf("Width (input): %d\n", &square.x);
	scanf("Height (input): %d", &square.y);
	square.area = square.x * square.y;
	square.per = 2*(square.x + square.y);
	square.hyp = sqrt(square.x * square.x + square.y * square.y);
	int* X = &square.x;
	int* Y = &square.y;
	int* Area = &square.area;
	int* Per = &square.per;
	double* Hyp = &square.hyp;
	printf("square.x: %d        |        \t&square.x (X): %p        \n", square.x, X);
	printf("square.y: %d        |        \t&square.y (Y): %p        \n", square.y, Y);
	printf("square.area: %d       |       \t&square.area (Area): %p     \n", square.area, Area);
	printf("square.per: %d         |        \t&square.per (Per): %p      \n", square.per, Per);
	printf("square.hyp: %f  |    \t&square.hyp (Hyp): %p        \n", square.hyp, Hyp);
}
