#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
#include<unistd.h>

int numOfData = 45;
bool in(int val, int *arr, int size){
	int i;
	for (i = 0; i < size; i++){
		if (arr[i] == val)
			return true;
	}
	return false;
}
int arrsize(int * arr){
	return numOfData;
}

int main(int argv, char *argc){
	char type[20];
	printf("Enter mean, median, mode or range: ");
	scanf("%s", type);
	printf("Enter number of data: ");
	scanf("%d", &numOfData);
	int data[numOfData];
	for (int x = 0; x < numOfData; x++){
		int y;
		printf("Enter data: ");
		scanf("%d", &y);
		data[x] = y;
	}
	if (strcmp(type, "mean") == 0){
		double sum = 0.00;
		for (int x = 0; x < numOfData; x++){
			sum += data[x];
		}
		printf("Mean: %g\n", sum/numOfData);
	}else if (strcmp(type, "median") == 0){
		while (1){
			int swapped = 0;
			for (int x = 0; x < numOfData-1; x++){
				if (data[x] > data[x+1]){
					int temp = data[x];
					data[x] = data[x+1];
					data[x+1] = temp;
					swapped = 1;
				}
			}
			if (swapped == 0){
				break;
			}
		}
		if (numOfData%2 == 0){
			int midsum = data[(numOfData/2)-1]+data[numOfData/2];
			double mid = midsum/2.00;
			printf("Median: %g\n", mid);
		}else {
			int a = (numOfData/2)+0.5;
			printf("Median: %d\n", data[a]);
		}
	}else if (strcmp(type, "mode") == 0){
		printf("%d\n", arrsize(data));
	}else if (strcmp(type, "range") == 0){
		while (1) {
			int swapped = 0;
			for (int x = 0; x < numOfData-1; x++){
				if (data[x] > data[x+1]){
					int temp = data[x];
					data[x] = data[x+1];
					data[x+1] = temp;
					swapped = 1;
				}
			}
			if (swapped == 0){
				break;
			}
		}
		printf("Range: %d\n", data[numOfData-1]-data[0]);
	}
}
