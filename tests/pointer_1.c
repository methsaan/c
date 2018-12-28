#include <stdio.h>

//int byReference(int *);

int main(int argc, char argv[]) {
    int x = 22;
    int *y;
    printf("Memory address of x is %p\n", &x);
    printf("by value is %d\n", x);
    printf("%d\n", *(&x) * *(&x));
    //byReference(&x);
}

//int byReference(int *y) {
//    printf("%d\n", *y**y);
//}
