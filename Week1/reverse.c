#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    char s[100];
    fgets(s, 100, stdin);
    int slength = 0;
    int i;
    while(s[i] != '\0') {
        slength += 1;
        i++;
    }
    //char sr[slength];
    char sr[slength + 1];

    for(i = 0; i < slength; i++) {
        //printf("%c", s[slength-i-1]);
        sr[i] = s[slength-i-1];
    }
    sr[slength] = '\0';
    printf("%s\n", sr);
    return 0;
}
//[a, b, c, '' , .... ,'' ,'' ]