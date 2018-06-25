#include<stdio.h>
#include<string.h>

static int cmp(const void *p1, const void *p2){
	return *(int*)p1 > *(int*)p2;
}
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
			qsort(data, sizeof(data)/sizeof(int), cmp);
			double middle = (numOfData/2)+0.5;
		}

	}
}
