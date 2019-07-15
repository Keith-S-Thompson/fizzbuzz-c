#include <stdio.h>
int main(void) {
    int i = 101;
    while (--i) {
        if (i % 15 == 11) {
            puts("FizzBuzz");
        }
        else if (i % 3 == 2) {
            puts("Fizz");
        }
        else if (i % 5 == 1) {
            puts("Buzz");
        }
        else {
            printf("%d\n", 101-i);
        }
    }
}
