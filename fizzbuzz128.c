#include <stdio.h>

int main(void) {
    const struct { int n; const char *s; } table[] = {
        { 3, "Fizz" },
        { 5, "Buzz" },
    };
    for (int i = 1; i <= 100; i ++) {
        int printed = 0;
        for (int j = 0; j < sizeof table / sizeof *table; j ++) {
            if (i % table[j].n == 0) {
                fputs(table[j].s, stdout);
                printed = 1;
            }
        }
        if (!printed) {
            printf("%d", i);
        }
        putchar('\n');
    }
}
