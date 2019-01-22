#include <stdio.h>

static void num(int n) { printf("%d\n", n); }
static void fizz(int n) { puts("Fizz"); }
static void buzz(int n) { puts("Buzz"); }
static void fizzbuzz(int n) { puts("FizzBuzz"); }
static void (*const f[])(int) = { num, fizz, buzz, fizzbuzz };

int main(void) {
    for (int i = 1; i <= 100; i ++) {
        f[(3 << (i%15*2) & 19142723) >> (i%15*2)](i);
    }
}
