#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv){
	srand(time(NULL));
	int len;
	printf("Enter length: ");
	scanf("%d", &len);
	int arr[len];
	for (int x = 0; x < len; x++){
		printf("Enter the next element: ");
		scanf("%d", &arr[x]);
	}
	for (int x = 0; x < 4; x++){
		stdin
	}
	for (int x = 0; x < sizeof(arr)/sizeof(*arr); x++){
		printf("%d\n", arr[x]);
	}
}
