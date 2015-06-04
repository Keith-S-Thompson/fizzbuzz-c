#include <stdio.h>
int main(void) {
    for (int i = 1; i <= 100; i ++) {
        printf(i % 15 == 0 ? "FizzBuzz\n" :
               i %  3 == 0 ? "Fizz\n" :
               i %  5 == 0 ? "Buzz\n" :
                             "%d\n",
               i);
    }
}
