#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
    for (int i = 1; i <= 100; i ++) {
        char line[9] = "";
        i % 3 || strcat(line, "Fizz");
        i % 5 || strcat(line, "Buzz");
        *line || sprintf(line, "%d", i);
        puts(line);
    }
}
