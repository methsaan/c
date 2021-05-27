#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv) {
	FILE *fp;
	char code[500];
	int declareCodeIdx = 0;

	while (strcmp(code, "return 0;\n") != 0) {
		fp = fopen("execfile.c", "w+");
		printf("Enter code: ");
		fgets(code, 500, stdin);
		for (int x = 0; code[x] != '\0'; x++) {
			declareCode[declareCodeIdx] = code[x];
			declareCodeIdx++;
		}
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
		for (int x = 0; x < declareCodeIdx; x++) {
			fprintf(fp, "%c", declareCode[x]);
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
		// doesn't work, delete line from code array
		fclose(fp2);
	}
	system("gcc exec.c");
}
