#include <stdio.h>
int main(void) {
    for (int i = 1; i <= 100; i ++) {
        int printed = 0;
        if (i % 3 == 0) {
            fputs("Fizz", stdout);
            printed = 1;
        }
        if (i % 5 == 0) {
            fputs("Buzz", stdout);
            printed = 1;
        }
        if (!printed) {
            printf("%d", i);
        }
        putchar('\n');
    }
}
