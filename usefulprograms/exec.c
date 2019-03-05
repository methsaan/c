#include<stdio.h>

int main(int argc, char *argv) {
	FILE *fp;
	char code[500];
	scanf("%s", code);
	fp = fopen("execfile.c" , "w");
	fseek(fp, 6, SEEK_SET);
	fprintf(fp, "EEEEE\n");
	fclose(fp);
}
