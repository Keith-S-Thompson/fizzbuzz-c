#include <stdio.h>

void print    (int n) { printf("%d", n); }
void fizz     (int n) { fputs("Fizz", stdout); }
void buzz     (int n) { fputs("Buzz", stdout); }
void fizzbuzz (int n) { fizz(n); buzz(n); }

void (*const arr[])(int) = { print, fizz, buzz, fizzbuzz };

int main(void) {
    for (int i = 1; i <= 100; i ++) {
        arr[!(i%3)+(!(i%5)<<1)](i);
        putchar('\n');
    }
    return 0;
}
