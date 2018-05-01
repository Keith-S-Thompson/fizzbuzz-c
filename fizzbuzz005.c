#include <stdio.h>
int main(void) {
    for (int i = 1; i <= 100; i ++) {
        int chars_printed = 0;
        if (i % 3 == 0) {
            chars_printed += printf("Fizz");
        }
        if (i % 5 == 0) {
            chars_printed += printf("Buzz");
        }
        if (chars_printed == 0) {
            printf("%d", i);
        }
        putchar('\n');
    }
}
