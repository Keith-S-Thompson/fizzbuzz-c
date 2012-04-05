#include <stdio.h>

void fizz     (int n) { puts("Fizz"); }
void buzz     (int n) { puts("Buzz"); }
void fizzbuzz (int n) { puts("FizzBuzz"); }
void print    (int n) { printf("%d\n", n); }

int main(void) {
    void (*funcs[101])(int) = { 0 };

    for (int i = 3;  i <= 100; i += 3)  funcs[i] = fizz;
    for (int i = 5;  i <= 100; i += 5)  funcs[i] = buzz;
    for (int i = 15; i <= 100; i += 15) funcs[i] = fizzbuzz;
    for (int i = 1; i <= 100; i ++) {
        if (funcs[i] == NULL) funcs[i] = print;
    }

    for (int i = 1; i <= 100; i ++) funcs[i](i);

    return 0;
}
