#include <stdio.h>

static void FizzBuzz(int n) {
    n - 1       ? FizzBuzz(n - 1)  : (void)FizzBuzz,
    n % 15 == 0 ? puts("FizzBuzz") :
    n %  3 == 0 ? puts("Fizz")     :
    n %  5 == 0 ? puts("Buzz")     :
    printf("%d\n", n);
}

int main(void) {
    FizzBuzz(100);
}
