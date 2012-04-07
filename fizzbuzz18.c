#include <stdio.h>
int main(void) {
    for (int i = 1; i <= 100; i ++) {
        if (i%3*(i%5)) {
            printf("%d\n", i);
        }
        else {
            i%3||fputs("Fizz", stdout);
            i%5||fputs("Buzz", stdout);
            putchar('\n');
        }
    }
    return 0;
}
