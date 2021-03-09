#include <stdio.h>
#include <stdlib.h>

int atoii(const char s[]) {
    int i;
    int res = 0;
    for (i = 0; s[i] != '\0'; i++) {
        res = res*10 + s[i] - '0';
    }
    return res;
}

int main() {
    printf("%d\n", atoii("1111"));
    printf("%d", '1');
    return 0;
}