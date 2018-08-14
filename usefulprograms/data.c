#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
#include<unistd.h>
#define SIZEOF(var) ((char*)(&var + 1) - (char*)&var)

int numOfData = 45;
int arrLen(int *aiData){
	int tot = 0;
	tot = *(&aiData + 1) - aiData;
	return tot;
}
int *rmdup(int * array, int length){
	int **newArr = &array;

	return *newArr;
}
//int arrMax(int * arr, int size){
//	return 0;
//	//return largest number in array
//}
//int frequency(int * arr, int num){
//	return 0;
//	//return frequency of number in array
//}
//int mode(int arr[], int new[]){
//	int numOfEachNumInArr[NELEMS(new)];
//	for (int x = 0; x < NELEMS(new); x++){
//		numOfEachNumInArr[x] = frequency(arr, x);
//	}
//	return arrMax(numOfEachNumInArr, numOfData);
//}
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
		int *newArray = rmdup(data, numOfData);
		printf("Length of new array: %d\n", arrLen(newArray));
		for (int x = 0; x < 10; x++){
			printf("%d ", newArray[x]);
		}
		printf("\n");
		//printf("Mode: %d\n", mode(data, newArray));
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
