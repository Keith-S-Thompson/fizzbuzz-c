#include <stdio.h>

static void print    (int n) { printf("%d", n); }
static void fizz     (int n) { fputs("Fizz", stdout); }
static void buzz     (int n) { fputs("Buzz", stdout); }
static void fizzbuzz (int n) { fizz(n); buzz(n); }

static void (*const arr[])(int) = { print, fizz, buzz, fizzbuzz };

int main(void) {
    for (int i = 1; i <= 100; i ++) {
        arr[!(i%3)+(!(i%5)<<1)](i);
        putchar('\n');
    }
}
