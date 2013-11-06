#include <stdio.h>
int main(void) {
    for (int i = 1; i <= 100; i ++) {
        int c = 0;
        i%3||(c+=printf("Fizz"));
        i%5||(c+=printf("Buzz"));
        c||printf("%d", i);
        putchar('\n');
    }
}
