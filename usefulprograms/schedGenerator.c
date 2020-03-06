#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int numOfReq;
	int numOfOp;
	printf("Enter number of required activities: ");
	scanf("%d", &numOfReq);
	printf("Enter number of optional activities: ");
	scanf("%d", &numOfOp);
	char *activitiesReq[numOfReq];
	char *reqTime1[numOfReq];
	char *reqTime2[numOfReq];
	char *activitiesOp[numOfOp];
	for (int x = 0; x < numOfOp; x++) {
		printf("Enter optional activity %d: ", x+1);
		scanf("%s", activitiesOp[x]);
	}
	for (int x = 0; x < numOfReq; x++) {
		printf("Enter required activity %d beginning and end time: ", x+1);
		scanf("%s %s %s", activitiesReq[x], reqTime1, reqTime2);
	}
}
