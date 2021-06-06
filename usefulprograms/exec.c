#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv) {
	FILE *fp;
	char inputCode[50];
	char code[1500];
	int codeIdx = 0;
	int lines[50];
	int lineIdx = 0;

	while (strcmp(code, "return 0;\n") != 0) {
		fp = fopen("execfile.c", "w");
		printf("Enter command: ");
		fgets(inputCode, 50, stdin);
		for (int x = 0; inputCode[x] != '\0'; x++) {
			code[codeIdx] = inputCode[x];
			codeIdx++;
		}
		lines[lineIdx] = codeIdx;
		lineIdx++;
		for (int x = 0; x < 500; x++) {
			code[x] = '\0';
		}
		fprintf(fp, "#include <stdio.h>\n");
		fprintf(fp, "#include <stdlib.h>\n");
		fprintf(fp, "#include <math.h>\n");
		fprintf(fp, "#include <string.h>\n");
		fprintf(fp, "#include <stdbool.h>\n");
		fprintf(fp, "#include <ctype.h>\n\n");
		fprintf(fp, "int main(int argc, char *argv) {\n");
		for (int x = 0; x < codeIdx; x++) {
			fprintf(fp, "%c", code[x]);
		}
		fprintf(fp, "%s", code);
		fprintf(fp, "}\n");
		fclose(fp);
		char execute[800];
		strcpy(execute, "");
		char tempExecute[50];
		system("gcc execrun.c");
		system("./a.out");
		system("cat errors.txt");
		int size;

		FILE *fp2 = fopen("errors.txt", "r");
		if (fp2 != NULL) {
			fseek(fp2, 0, SEEK_END);
			size = ftell(fp2);
			if (size == 0) {
				
			}
		}
		fclose(fp2);
	}
	system("gcc exec.c");
}
