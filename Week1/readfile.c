#include <stdio.h>

int main() {
    FILE *fp;
    char str[1000];
    char* filename = "sample.txt";
    fp = fopen(filename, "r");

if(fp == NULL) {
    printf("file couldnt be opened");
    return 1;
} else {
    while(fgets(str, 1000, fp) != NULL) {
        printf("%s", str);
    }
    printf("\n");
    fclose(fp);
    return 1;
}

}