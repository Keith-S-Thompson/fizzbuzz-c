#include <stdio.h>

static void fizz(int n) {
    fputs("Fizz", stdout);
}

static void buzz(int n) {
    fputs("Buzz", stdout);
}

static void print(int n) {
    printf("%d", n);
}

static void nothing(int n) {
}

static void (*first(int n))(int) {
    return !(n%3) ? fizz : nothing;
}

static void (*second(int n))(int) {
    return !(n%5) ? buzz : n%3 ? print : nothing;
}

int main(void) {
    for (int i = 1; i <= 100; i ++) {
        first(i)(i);
        second(i)(i);
        putchar('\n');
    }
}
