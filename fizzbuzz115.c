#include <stdio.h>
int main(void) {
    const char *format = "FizzBuzz\n\0Fizz\n\0%d\n";
    for (int i = 1; i <= 100; i ++) {
        printf(format + (i % 15 == 0 ? 0 :
                         i % 3 == 0 ? 10 :
                         i % 5 == 0 ? 4 : 16), i);
    }
}
