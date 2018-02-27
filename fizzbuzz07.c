#include <stdio.h>
int main(void) {
    for (int i = 1; i <= 100; i ++) {
        !(i%15) && (puts("FizzBuzz")||1ll) ||
        !(i%3)  && (puts("Fizz")||1ll) ||
        !(i%5)  && (puts("Buzz")||1ll) ||
        printf("%d\n", i);
    }
}
