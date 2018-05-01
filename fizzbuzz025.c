#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
    for (int i = 1; i <= 100; i ++) {
        int n = 0;
        i%3 || printf("%s%n", "Fizz", &n);
        i%5 || printf("%s%n", "Buzz", &n);
        n   || printf("%d", i);
        putchar('\n');
    }
}
