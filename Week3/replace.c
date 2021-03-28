#include <stdio.h>
#include <string.h>

int main(int arc, char** argv) {
    FILE * infile_ptr = fopen(argv[1], "r");
    FILE * outfile_ptr = fopen(argv[2], "w");

    if (infile_ptr == NULL) {
        printf("Failed to open the infile. \n");
        return -1;
    }
    
    // char find[] = argv[3];
    // char replace[] = argv[4];
    char array[4096];

    int i = 0;
    while (fread(&array[i], 1, 1, infile_ptr)) {
       i ++;
    }
    
    i = 0;
    while (i < strlen(array)) {
        
    }
    
    
}