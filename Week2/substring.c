#include <stdio.h>
int my_strlen();

int substring(const char* line, const char* substr) {
    int i;
    for(i = 0; i < my_strlen(line); i ++) {
        int j;
        for(j = 0; j < my_strlen(substr); j++) {
            if(line[i+j] == substr[j]) {
                printf("%c", line[i+j]);
                printf("%c\n", substr[j]);
                if(j == my_strlen(substr) -1) {
                    return i;
                }
            } else {
                break;
            }
        }
    }
    return -1;
}

int main() {
    printf("%d\n", substring("racecar", "car"));
    printf("%d\n", substring("onlephonk", "one"));
}