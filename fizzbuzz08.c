#include <stdio.h>
int main(void) {
    for (int i = 1; i <= 100; i ++) {
        i % 3 && i % 5 ? printf("%d\n", i) :
        puts(!(i % 15) ? "FizzBuzz" : !(i % 3) ? "Fizz" : "Buzz");
    }
    return 0;
}
