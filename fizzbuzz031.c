#include <stdio.h>
int main(void) {
    for (int i = 1; i <= 100; i ++) {
        const int three = printf(i % 3 ? "" : "Fizz");
        three + printf(i % 5 ? "" : "Buzz") || printf("%d", i);
        putchar('\n');
    }
}
