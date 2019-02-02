#include <stdio.h>

int main(int argc, char *argv){
	for (int x = 0; x < 1.0/0.0; x++) {
		printf("Infinite loop\n");
	}
}
