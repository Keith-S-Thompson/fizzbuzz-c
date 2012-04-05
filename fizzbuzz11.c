#include <stdio.h>

void fizz     (int n) { puts("Fizz"); }
void buzz     (int n) { puts("Buzz"); }
void fizzbuzz (int n) { puts("FizzBuzz"); }
void print    (int n) { printf("%d\n", n); }

void (*func(int n))(int) {
    return !(n%15) ? fizzbuzz : !(n%3) ? fizz : !(n%5) ? buzz : print;
}

int main(void) {
    for (int i = 1; i <= 100; i ++) {
        func(i)(i);
    }
    return 0;
}
