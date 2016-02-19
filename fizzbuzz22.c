#include <stdio.h>

static void fizz     (int n) { puts("Fizz"); }
static void buzz     (int n) { puts("Buzz"); }
static void fizzbuzz (int n) { puts("FizzBuzz"); }
static void print    (int n) { printf("%d\n", n); }

int main(void) {
    void (*funcs[15])(int) = { 0 };
    for (int i = 0; i < 15; i += 3) funcs[i] = fizz;
    for (int i = 0; i < 15; i += 5) funcs[i] = buzz;
    funcs[0] = fizzbuzz;
    for (int i = 0; i < 15; i ++) {
        if (funcs[i] == NULL) funcs[i] = print;
    }
    for (int i = 1; i <= 100; i ++) funcs[i%15](i);
}
