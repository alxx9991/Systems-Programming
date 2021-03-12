#include <stdio.h>

int main(int argc, char **argv) {
    char str[100];
    fgets(str, 100, stdin);

    int i = 0;
    while(str[i] != 10) {
        if (!(str[i] < 97 || str[i] > 122)) {
            str[i] -= 32;
        }
        printf("%c", str[i]);
        i ++;
    }

    printf("\n");
    return 0;
}