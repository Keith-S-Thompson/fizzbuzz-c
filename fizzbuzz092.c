#include <stdio.h>
int main(void) {
    for (int i = 1; i % 15 == 0 ? puts("FizzBuzz") : i % 3 == 0 ? puts("Fizz") : i % 5 == 0 ? puts("Buzz") : printf("%d\n", i), i < 100; i ++);
}
