#include <stdio.h>

int main(void) {
    enum state {
        s00, s01, s02, s03, s04,
        s10, s11, s12, s13, s14,
        s20, s21, s22, s23, s24,
        end
    };
    const enum state next[] = {
        s11, s12, s13, s14, s10,
        s21, s22, s23, s24, s20,
        s01, s02, s03, s04, s00
    };
    enum state state = s11;
    int i = 1;

    while (state != end) {
        switch (state) {
            case s01: case s02: case s03: case s04:
                puts("Fizz");
                break;
            case s10: case s20:
                puts("Buzz");
                break;
            case s00:
                puts("FizzBuzz");
                break;
            default:
                printf("%d\n", i);
                break;
        }
        i++;
        if (i > 100) {
            state = end;
        }
        else {
            state = next[state];
        }
    }
}
