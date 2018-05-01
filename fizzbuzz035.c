#include <stdio.h>

static void fizz     (int n) { puts("Fizz"); }
static void buzz     (int n) { puts("Buzz"); }
static void fizzbuzz (int n) { puts("FizzBuzz"); }
static void print    (int n) { printf("%d\n", n); }

static void line(int n) {
    (!(n%15) ? fizzbuzz : !(n%3) ? fizz : !(n%5) ? buzz : print)(n);
}

static void recurse(int first, int last, void (*func)(int)) {
    if (first <= last) {
        func(first);
        recurse(first+1, last, func);
    }
}

int main(void) {
    recurse(1, 100, line);
}
