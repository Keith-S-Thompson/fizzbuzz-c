#include <stdio.h>
int main(void) {
    for (int i = 1; i <= 100; i ++) {
        !(i%15) && puts("FizzBuzz") ||
        !(i%3)  && puts("Fizz") ||
        !(i%5)  && puts("Buzz") ||
        printf("%d\n", i);
    }
    return 0;
}
