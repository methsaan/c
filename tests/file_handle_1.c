#include <stdio.h>

int main(int argc, char argv[]) {
    int a = 100;
    char c = 'c';
    FILE* fp = fopen("/tmp/file1.txt","w");
    fprintf(fp, "This is file content without formatting");
    fprintf(fp, "This is file content with formatting\n");
    fprintf(fp, "This is file content and the character is %c and number %d\n",c,a);
}
