#include <stdio.h>

static void FizzBuzz(int n) {
    n - 1 ? FizzBuzz(n - 1) : (void)FizzBuzz,
    n % 15 ? n % 3 ? n % 5 ?
    printf("%d\n", n) : puts("Buzz") : puts("Fizz") : puts("FizzBuzz");
}

int main(void) {
    FizzBuzz(100);
}
