#include <stdio.h>
int main(void) {
    const char *const format = {
        "FizzBuzz\n\0"
        "Fizz\n\0"
        "%d\n"
    };
    enum {
        FizzBuzz = 0,
        Fizz = 10,
        Buzz = 4,
        num = 16
    };
    for (int i = 1; i <= 100; i ++) {
        printf(format + (i % 15 == 0 ? FizzBuzz :
                         i %  3 == 0 ? Fizz :
                         i %  5 == 0 ? Buzz :
                                       num),
               i);
    }
}
