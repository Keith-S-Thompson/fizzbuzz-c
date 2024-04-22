#include <stdio.h>

#define print1(n) \
    ((n) % 15 == 0 ? puts("FizzBuzz") : \
    (n) %  3 == 0 ? puts("Fizz") : \
    (n) %  5 == 0 ? puts("Buzz") : \
    printf("%d\n", (n)))

#define print5(n) \
    (print1(n), \
    print1(n+1), \
    print1(n+2), \
    print1(n+3), \
    print1(n+4))

#define print25(n) \
    (print5(n), \
    print5(n+5), \
    print5(n+10), \
    print5(n+15), \
    print5(n+20))

#define print100(n) \
    (print25(n), \
    print25(n+25), \
    print25(n+50), \
    print25(n+75))

int main(void) {
    print100(1);
}
