#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
    for (int i = 1; i <= 100; i ++) {
        char line[9];
        line[0] = '\0';
        if (i % 3 == 0) {
            strcat(line, "Fizz");
        }
        if (i % 5 == 0) {
            strcat(line, "Buzz");
        }
        if (line[0] == '\0') {
            sprintf(line, "%d", i);
        }
        puts(line);
    }
}
