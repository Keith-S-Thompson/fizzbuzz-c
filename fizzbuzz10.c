#include <stdio.h>

void fizz     (int n) { puts("Fizz"); }
void buzz     (int n) { puts("Buzz"); }
void fizzbuzz (int n) { puts("FizzBuzz"); }
void print    (int n) { printf("%d\n", n); }

int main(void) {
    void (*funcs[100])(int) = { 0 };

    for (int i = 3;  i <= 100; i += 3)  funcs[i-1] = fizz;
    for (int i = 5;  i <= 100; i += 5)  funcs[i-1] = buzz;
    for (int i = 15; i <= 100; i += 15) funcs[i-1] = fizzbuzz;
    for (int i = 1; i <= 100; i ++) {
        if (funcs[i-1] == NULL) funcs[i-1] = print;
    }

    for (int i = 1; i <= 100; i ++) funcs[i-1](i);
}
