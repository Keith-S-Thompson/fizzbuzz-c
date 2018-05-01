#include <stdio.h>
int main(void) {
    const char *const fmt[] = { "%d\n", "Fizz\n", "Buzz\n", "FizzBuzz\n" };
    for (int i = 1; i <= 100; i ++) {
        printf(fmt[!(i%3) + (!(i%5)<<1)], i);
    }
}
