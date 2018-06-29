#include <stdio.h>
int main(void) {
    for (int i = 1; i <= 100; i ++) {
        int p = 0;
        p || i % 15 || puts((p++, "FizzBuzz"));
        p || i %  3 || puts((p++, "Fizz"));
        p || i %  5 || puts((p++, "Buzz"));
        p || printf("%d\n", i);
    }
}
