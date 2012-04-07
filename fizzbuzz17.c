#include <stdio.h>

void fizzbuzz(int lo, int hi) {
    if (lo <= hi) {
        int i = (lo + hi) / 2;
        if (lo < hi) {
            fizzbuzz(lo, i-1);
        }

        if      (i % 15 == 0) { puts("FizzBuzz"); }
        else if (i % 3  == 0) { puts("Fizz"); }
        else if (i % 5  == 0) { puts("Buzz"); }
        else                  { printf("%d\n", i); }

        if (lo < hi) {
            fizzbuzz(i+1, hi);
        }
    }
}

int main(void) {
    fizzbuzz(1, 100);
    return 0;
}
