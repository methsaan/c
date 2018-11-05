#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv){
	char *command;
	char *command2;
	char *fullcommand;
	system("echo \"welcome to bash.c\"");
	while (1){
		fullcommand = "";
		printf("Enter a bash command: ");
		scanf("%s%s", command, command2);
		strcat(fullcommand, command);
		strcat(fullcommand, " ");
		strcat(fullcommand, command2);
		printf("%p\n", fullcommand);
		system(fullcommand);
	}
	return 0;
}
