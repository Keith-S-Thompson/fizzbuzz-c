#include <stdio.h>
int main(void) {
    int imod3 = 0, imod5 = 0;
    for (int i = 1; i <= 100; i ++) {
        imod3 ++; if (imod3 == 3) imod3 = 0;
        imod5 ++; if (imod5 == 5) imod5 = 0;
        if (imod3 == 0 && imod5 == 0) {
            puts("FizzBuzz");
        }
        else if (imod3 == 0) {
            puts("Fizz");
        }
        else if (imod5 == 0) {
            puts("Buzz");
        }
        else {
            printf("%d\n", i);
        }
    }
}
