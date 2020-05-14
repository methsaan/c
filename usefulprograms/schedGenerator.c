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
	char *schedTime[2];
	printf("Enter wake up time: ");
	schedTime[0] = malloc(100 * sizeof(char));
	schedTime[1] = malloc(100 * sizeof(char));
	scanf("%99s", schedTime[0]);
	printf("Enter sleep time: ");
	scanf("%99s", schedTime[1]);
	char *activitiesOp[numOfOp];
	for (int x = 0; x < numOfOp; x++) {
		activitiesOp[x] = malloc(100 * sizeof(char));
		printf("Enter optional activity %d: ", x+1);
		scanf("%99s", activitiesOp[x]);
	}
	for (int x = 0; x < numOfReq; x++) {
		activitiesReq[x] = malloc(100 * sizeof(char));
		reqTime1[x] = malloc(100 * sizeof(char));
		reqTime2[x] = malloc(100 * sizeof(char));
		printf("Enter required activity %d beginning and end time: ", x+1);
		scanf("%99s %99s %99s", activitiesReq[x], reqTime1[x], reqTime2[x]);
	}
	int reqTimeLen[numOfReq];
	for (int x = 0; x < numOfReq; x++) {
		int beginHour = (reqTime1[x][0]-'0')*10 + (reqTime1[x][1]-'0');
		int beginMin = (reqTime1[x][3]-'0')*10 + (reqTime1[x][4]-'0');
		int endHour = (reqTime2[x][0]-'0')*10 + (reqTime2[x][1]-'0');
		int endMin = (reqTime2[x][3]-'0')*10 + (reqTime2[x][4]-'0');
		int lenHour = endHour - beginHour;
		int lenMin = endMin - beginMin;
		if (lenMin < 0) {
			lenHour -= 1;
			lenMin += 60;
		}
		printf("%s: %d hours %d minutes\n", activitiesReq[x], lenHour, lenMin);
	}
}
