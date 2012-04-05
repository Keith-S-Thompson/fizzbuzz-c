/*
 * This version works only if stdout is seekable
 */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
int main(void) {
    for (int i = 1; i <= 100; i ++) {
        long start = ftell(stdout);
        if (start == -1L) {
            perror("ftell");
            exit(EXIT_FAILURE);
        }
        if (i % 3 == 0) {
            fputs("Fizz", stdout);
        }
        if (i % 5 == 0) {
            fputs("Buzz", stdout);
        }
        if (ftell(stdout) == start) {
            printf("%d", i);
        }
        putchar('\n');
    }
    return 0;
}
