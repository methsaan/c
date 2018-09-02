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
	square.x = 8;
	square.y = 9;
	square.area = square.x * square.y;
	square.per = 2*(square.x + square.y);
	square.hyp = sqrt(square.x * square.x + square.y * square.y);
	printf("square.x: %d\n", square.x);
	printf("square.y: %d\n", square.y);
	printf("square.area: %d\n", square.area);
	printf("square.per: %d\n", square.per);
	printf("square.hyp: %f\n", square.hyp);
}
