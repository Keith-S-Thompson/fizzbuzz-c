#include <stdio.h>

void fizz(int n) {
    fputs("Fizz", stdout);
}

void buzz(int n) {
    fputs("Buzz", stdout);
}

void print(int n) {
    printf("%d", n);
}

void nothing(int n) {
}

void (*first(int n))(int) {
    return !(n%3) ? fizz : nothing;
}

void (*second(int n))(int) {
    return !(n%5) ? buzz : n%3 ? print : nothing;
}

int main(void) {
    for (int i = 1; i <= 100; i ++) {
        first(i)(i);
        second(i)(i);
        putchar('\n');
    }
}
