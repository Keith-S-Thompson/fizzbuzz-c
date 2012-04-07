#include <stdio.h>

void fizzbuzz(int i) {
    if (i > 1) {
        fizzbuzz(i-1);
    }
    if      (i % 15 == 0) { puts("FizzBuzz"); }
    else if (i % 3  == 0) { puts("Fizz"); }
    else if (i % 5  == 0) { puts("Buzz"); }
    else                  { printf("%d\n", i); }
}

int main(void) {
    fizzbuzz(100);
    return 0;
}
