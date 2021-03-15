#include <stdio.h>

int main() {
    const float PI = 3.1415;
    float r;
    printf("What is the radius? ");
    scanf("%f", &r);
    printf("%f\n", r*r*r*(4.0/3.0)*PI);
}