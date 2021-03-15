#include <stdio.h>
#include <string.h>

int encode_run(const char* sequence, unsigned int len, char* buf, unsigned int buf_len) {
    int i;
    int counter = 0;
    int buf_counter = 0;
    for(i = 0; i < len; i++) {
        if (i!= 0) {
            if(sequence[i] != sequence[i-1]) {
                char counter_char = counter + 48;
                buf[buf_counter] = counter_char;
                buf_counter += 1;
                counter = 0;
            }
        }
        counter ++;
    }
    char counter_char = counter + 48;
    buf[buf_counter] = counter_char;
    return 0;
}

int main() {
    char buf[128] = {};
    char sequence[] = "1122333334423";
    unsigned int len = 13;
    
    encode_run(sequence, len, buf, 128);
    printf("%s\n", buf);
}