#include <stdio.h>
int main(void) {
    for (int i = 1; i <= 100; i ++) {
        printf(i % 3 ? "" : "Fizz") + printf(i % 5 ? "" : "Buzz") || printf("%d", i);
        putchar('\n');
    }
    return 0;
}
