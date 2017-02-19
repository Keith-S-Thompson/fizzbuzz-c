#include <stdio.h>
int main(void) {
    for (int i = 1; i <= 100; i ++) {
        i % 3 == 0               && fputs("Fizz", stdout);
        i % 3 != 0 && i % 5 != 0 && printf("%d", i);
        i % 5 == 0               && fputs("Buzz", stdout);
        putchar('\n');
    }
}
