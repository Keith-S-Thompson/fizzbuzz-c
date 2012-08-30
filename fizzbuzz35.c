#include <stdio.h>

void fizz     (int n) { puts("Fizz"); }
void buzz     (int n) { puts("Buzz"); }
void fizzbuzz (int n) { puts("FizzBuzz"); }
void print    (int n) { printf("%d\n", n); }

void line(int n) {
    (!(n%15) ? fizzbuzz : !(n%3) ? fizz : !(n%5) ? buzz : print)(n);
}

void recurse(int first, int last, void (*func)(int)) {
    if (first <= last) {
        func(first);
        recurse(first+1, last, func);
    }
}

int main(void) {
    recurse(1, 100, line);
    return 0;
}
