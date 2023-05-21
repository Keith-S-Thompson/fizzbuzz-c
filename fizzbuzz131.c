#include <stdio.h>
#include <stdbool.h>
int main(void) {
    for (int i = 1; i <= 100; i ++) {
        bool by3, by5;
        by3 = i % 3 == 0 && 1+fputs("Fizz", stdout);
        by5 = i % 5 == 0 && 1+fputs("Buzz", stdout);
        by3 || by5 || printf("%d", i);
        putchar('\n');
    }
}
