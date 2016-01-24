#include <stdio.h>
int main(void) {
    for (int i = 1, x = 1, y = 1, z = 1;
         i <= 100;
         i ++, x ++, y ++, z ++)
    {
        x == 3  && (x = 0);
        y == 5  && (y = 0);
        z == 15 && (z = 0);
        if      (!z) puts("FizzBuzz");
        else if (!x) puts("Fizz");
        else if (!y) puts("Buzz");
        else         printf("%d\n", i);
    }
}
