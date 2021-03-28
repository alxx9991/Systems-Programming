#include <stdio.h>

int main(int argc, char** argv) {
    FILE * file_ptr = fopen(argv[1], "r");
    if (file_ptr == NULL) {
        return 1;
    }

    char c;
    int newline_count = 0;
    int word_count = 0;
    int char_count = 0;

    while(fread(&c, 1, 1, file_ptr) != 0) {
        printf("%c", c);
        char_count ++;
        if(c == ' ') {
            word_count ++;
        }
        if(c == '\n') {
            newline_count ++;
        }
    }
    printf("\n");

    printf("%d %d %d \n", newline_count, word_count, char_count);
}