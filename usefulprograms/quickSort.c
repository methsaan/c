#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv){
	srand(time(NULL));
	int len;
	scanf("%d", &len);
	int arr[len];
	for (int x = 0; x < len; x++){
		printf("Enter the next element: ");
		scanf("%d", &arr[x]);
	}
	int randomIndex;
	int temp;
	for (int x = 0; x < 4; x++){
		randomIndex = rand()%len;
		for (int y = 0; y < len; y++){
			if (arr[y] == arr[randomIndex]){
				continue;
			}else if (arr[y] < arr[randomIndex]){
				temp = arr[y];
				arr[y] = arr[randomIndex];

			}
		}
	}
}
