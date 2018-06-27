#include<stdio.h>
#include<string.h>

int main(int argv, char *argc){
	char type[20];
	int numOfData;
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
		printf("%.2f\n", sum/numOfData);
	}else if (strcmp(type, "median") == 0){
		if (numOfData%2 == 0){
			double middle = ((numOfData/2)+((numOfData/2)+1))/2;
		}else {
			for (int x = 0; x < numOfData-1; x++){
				if (data[x] > data[x+1]){
					data[x] = data[x+1];
					data[x+1] = data[x];
				}
			}
			for (int x = 0; x < numOfData;x++){
				printf("%d ", data[0]);
			}
			printf("\n");
			double middle = (numOfData/2)+0.5;
		}

	}
}
