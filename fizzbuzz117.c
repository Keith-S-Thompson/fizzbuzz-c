#include <stdio.h>
#include <stdlib.h>

static char *num(int n) {
    static char buf[3];
    return sprintf(buf, "%d", n), buf;
}

int line(int i) {
    static const char *const message[] = {
        [3] = "Fizz", [6] = "Fizz", [9] = "Fizz", [12] = "Fizz",
        [5] = "Buzz", [10] = "Buzz",
        [0] = "FizzBuzz",
        [14] = NULL,
    };
    return i == 101 ? 0 : puts(message[i%15] ? message[i%15] : num(i));
}

int fizzbuzz(int n) {
    return n == 1 ? line(n) : (fizzbuzz(n-1), line(n));
}

int main(void) {
    return fizzbuzz(101);
}
