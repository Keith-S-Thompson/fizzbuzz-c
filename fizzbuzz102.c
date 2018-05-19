#include <stdio.h>
#include <string.h>
int main(void) {
    for (int i = 1; i <= 100; i ++) {
        char line[10];
        sprintf(line, "%s%s%d", i % 3 ? "" : "Fizz", i % 5 ? "" : "Buzz", (i % 3 && i % 5) ? i*10 : 0);
        *strchr(line, '0') = '\0';
        puts(line);
    }
}
