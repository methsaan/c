#include<stdio.h>

int main(int argc, char *argv){
	int factors1[100];
	int factors2[100];
	int num1;
	int num2;
	int gcf;
	int len1 = 0;
	int len2 = 0;
	int cnt1 = 0;
	int cnt2 = 0;
	printf("Enter 2 numbers separated by a comma: ");
	scanf("%d, %d", &num1, &num2);
	for (int x = 1; x < num1; x++){
		if (((double)num1)/((double)x) == (double)((int)((double)num1/(double)x))){
			factors1[cnt1++] = num1/x;
			len1++;
		}
		if (((double)num2)/((double)x) == (double)((int)((double)num2/(double)x))){
			factors2[cnt2++] = num2/x;
			len2++;
		}
	}
	if (factors1[len1-1] != 1){
		factors1[len1++] = 1;
	}
	if (factors2[len2-1] != 1){
		factors2[len2++] = 1;
	}
	//printf("Factors of %d: ", num1);
	//for (int x = 0; x < len1; x++){
		//printf("%d ", factors1[x]);
	//}
	//printf("\nFactors of %d: ", num2);
	//for (int x = 0; x < len2; x++){
		//printf("%d ", factors2[x]);
	//}
	//printf("\n");
	int stat;
	for (int x = 0; x < len1; x++){
		for (int y = 0; y < len2; y++){
			if (factors1[x] == factors2[y]){
				gcf = factors1[x];
				stat = 1;
				break;
			}else {
				stat = 0;
			}
		}
		if (stat == 1){
			break;
		}
	}
	printf("GCF: %d\n", gcf);
}
