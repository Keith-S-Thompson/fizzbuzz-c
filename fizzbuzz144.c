#include <stdio.h>

#define define_funcs(x, y, z) \
    static void x(int n) { puts(#x); } \
    static void y(int n) { puts(#y); } \
    static void z(int n) { puts(#z); }
define_funcs(Fizz, Buzz, FizzBuzz)
static void print(int n) {
    const char s[3] = {n/10+'0',n%10+'0'};
    puts(s + (n < 10));
}
static void (*funcs[101])(int);

static void set(int n, void (*func)(int)) {
    for (int i = n; i <= 100; i += n) {
        funcs[i] = func;
    }
}

int main(void) {
    set(1, print);
    set(3, Fizz);
    set(5, Buzz);
    set(15, FizzBuzz);
    for (int i = 1; i <= 100; i ++) funcs[i](i);
}
