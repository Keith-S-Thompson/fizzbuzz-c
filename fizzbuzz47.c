#include <stdio.h>
int main(void) {
    for (int i = 1; i <= 100; i ++) {
        char line[9];
        line[0] = (i % 3 == 0 ? 'F' :
                   i % 5 == 0 ? 'B' : 
                   i < 10 ? i + '0' :
                   i / 10 + '0');
        line[1] = (i % 3 == 0 ? 'i' :
                   i % 5 == 0 ? 'u' : 
                   i < 10 ? '\0' :
                   i % 10 + '0');
        line[2] = (i % 3 == 0 || i % 5 == 0 ? 'z' : '\0');
        line[3] = (i % 3 == 0 || i % 5 == 0 ? 'z' : '\0');
        line[4] = (i % 15 == 0 ? 'B' : '\0');
        line[5] = (i % 15 == 0 ? 'u' : '\0');
        line[6] = (i % 15 == 0 ? 'z' : '\0');
        line[7] = (i % 15 == 0 ? 'z' : '\0');
        line[8] = '\0';
        puts(line);
    }
}
