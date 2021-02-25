#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv) {
	FILE *fp;
	FILE *fp2;
	char code[500];
	char origCode[500];
	char declareCode[1000];
	fp2 = fopen("execfile.c" , "r");
	int c,nl=0,nc=0;
	c=getc(fp2);
	origCode[0] = c;
	int idx = 1;
	int lines = 0;
	while(c!=EOF){
		if(c=='\n')
		nl++;
		nc++;
		c=getc(fp2);
		origCode[idx] = c;
		idx++;
		if (c == '\n') {
			lines++;
		}
		
	}
	int declareCodeIdx = 0;
	while (strcmp(code, "return 0;\n") != 0) {
		fp = fopen("execfile.c", "w+");
		printf("Enter code: ");
		fgets(code, 500, stdin);
		int codeLen = 0;
		for (int x = 0; code[x] != '\0'; x++) {
			codeLen++;
		}
		int hasDeclaration = 0;
		for (int x = 0; x < codeLen; x++) {
			if (code[x] == '=' ) {
				hasDeclaration++;
				break;
			}
		}
		if (hasDeclaration == 1) {
			for (int x = 0; code[x] != '\0'; x++){
				declareCode[declareCodeIdx] = code[x];
				declareCodeIdx++;
			}
			for (int x = 0; x < 500; x++) {
				code[x] = '\0';
			}
		}
		fprintf(fp, "#include <stdio.h>\n");
		fprintf(fp, "#include <stdlib.h>\n");
		fprintf(fp, "#include <math.h>\n");
		fprintf(fp, "#include <string.h>\n");
		fprintf(fp, "#include <stdbool.h>\n");
		fprintf(fp, "#include <ctype.h>\n\n");
		fprintf(fp, "int main(int argc, char *argv) {\n");
		for (int x = 0; x < declareCodeIdx; x++) {
			fprintf(fp, "%c", declareCode[x]);
		}
		fprintf(fp, "%s", code);
		fprintf(fp, "}\n");
		fclose(fp);
		char execute[800];
		strcpy(execute, "");
		char tempExecute[50];
		// go to execrun.c
		system("gcc execrun.c");
		system("./a.out");
		system("cat errors.txt");
	}
	system("gcc exec.c");
}
