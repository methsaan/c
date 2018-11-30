#include <stdio.h>

int main(int argc, char *argv) {
	int numOfOp;
	printf("Enter number of operations: ");
	scanf("%d", &numOfOp);
	char op[numOfOp];
	int num[numOfOp+1];
	int cnt1 = 0;
	int cnt2 = 0;
	printf("Enter first number: ");
	scanf("%d", &num[cnt1]);
	cnt1++;
	for (int x = 0; x < numOfOp; x++){
		getchar();
		printf("Enter next operator: ");
		op[cnt2] = getchar();
		getchar();
		if (x < numOfOp-1){
			printf("Enter next number: ");
			scanf("%d", &num[cnt1]);
			cnt1++;
		}
		cnt2++;
	}
	printf("Enter last number: ");
	scanf("%d", &num[cnt1]);
	cnt1 = 0;
	cnt2 = 0;
	printf("%d ", num[cnt1]);
	cnt1++;
	for (int x = 0; x < sizeof(num)/sizeof(*num) + sizeof(op)/sizeof(*op)-2; x++){
		printf("%c ", op[cnt2]);
		printf("%d ", num[cnt1]);
		cnt2++;
		cnt1++;
	}
	printf("%d\n", num[cnt1-1]);
}
