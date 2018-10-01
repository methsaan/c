#include<stdlib.h>
#include<stdio.h>

int main(int argc, char *argv){
	FILE *x = fopen("file.c", "w");
	fprintf(x, "#include <stdio.h>\n");
	fprintf(x, "\n");
	fprintf(x, "int main(int argc, char *argv){\n");
	fprintf(x, "\tprintf(\"hello\\n\");\n");
	fprintf(x, "}");
	fclose(x);
}
