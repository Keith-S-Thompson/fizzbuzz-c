#include <stdio.h>
int main(void) {
    for (int i = 1; i <= 100; i ++) {
        const int x = !(i%5)<<1|!(i%3);
        x&1 && fputs("Fizz", stdout);
        x&2 && fputs("Buzz", stdout);
        x&3 || printf("%d", i);
        putchar('\n');
    }
}
