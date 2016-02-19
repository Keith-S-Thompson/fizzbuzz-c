#include <stdio.h>

static void fizz     (int n) { puts("Fizz"); }
static void buzz     (int n) { puts("Buzz"); }
static void fizzbuzz (int n) { puts("FizzBuzz"); }
static void print    (int n) { printf("%d\n", n); }

void (*func(int n))(int) {
    return !(n%15) ? fizzbuzz : !(n%3) ? fizz : !(n%5) ? buzz : print;
}

int main(void) {
    for (int i = 1; i <= 100; i ++) {
        func(i)(i);
    }
}
