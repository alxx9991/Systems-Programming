#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n = 1;
    char in_list[3][100];
    char out_list[3][100];

    while (n <= 3) {
        printf("Enter Name and Score for batter %d: ", n);
        fgets(in_list[n], 100, stdin);
        
        int i = 0;
        int j = 0;
        char fname[100];
        char lname[100];
        char s_score[100];
        
        while(in_list[n][i] != ' '){
            fname[j] = in_list[n][i];
            i ++;
            j ++;
        }
        fname[j] = '\0';
        
        i++;
        j = 0;
        while(in_list[n][i] != ' '){
            lname[j] = in_list[n][i];
            i ++;
            j ++;
        } 
        lname[j] = '\0';

        i++;
        j = 0;
        while(in_list[n][i] != '\n'){
            s_score[j] = in_list[n][i];
            i ++;
            j ++;
        }
        s_score[j] = '\0';

        int score = atoi(s_score);
        
        char outchar[100];

        sprintf(outchar, "%c. %s %d\n", fname[0], lname, score);
        strcpy(out_list[n-1], outchar);

        n++;
    }
    
    int i = 0;
    while (i < 3) {
        printf("%s\n", out_list[i]);
        i += 1;
    }
    
    return 0;
}
