#include <stdio.h>
void swap (int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void) {
    int a = 2;
    int b = 3;
    swap(&a, &b);
    printf("%d\n", a);
    printf("%d", b);
    return 0;
}