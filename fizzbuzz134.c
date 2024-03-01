#include <stdio.h>

#ifndef __COUNTER__
#error "__COUNTER__ is not defined"
#endif

#define LINE(i) \
    i % 15 == 0 ? puts("FizzBuzz") : \
    i %  3 == 0 ? puts("Fizz") : \
    i %  5 == 0 ? puts("Buzz") : \
                  printf("%d\n", i)

int main(void) {
    __COUNTER__;
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
    LINE(__COUNTER__);
}
