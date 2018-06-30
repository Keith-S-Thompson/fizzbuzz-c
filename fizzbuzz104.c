#include <stdio.h>
int main(void) {
    for (int i = 1; i <= 100; i ++) {
        int p = 0;
        i % 3 || fputs((p++, "Fizz"), stdout);
        i % 5 || fputs((p++, "Buzz"), stdout);
        p || printf("%d", i);
        putchar('\n');
    }
}
