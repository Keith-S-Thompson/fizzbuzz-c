#include <stdio.h>
#include <string.h>

static char *nostrcat(char *dest, const char *src){}

int main(void) {
    for (int i = 1; i <= 100; i ++) {
        char line[9] = { 0 }, num[4];
        (i % 3 ? nostrcat : strcat)(line, "Fizz");
        (i % 5 ? nostrcat : strcat)(line, "Buzz");
        (line[0] ? nostrcat : strcat)(line, (sprintf(num, "%d", i), num));
        puts(line);
    }
}
