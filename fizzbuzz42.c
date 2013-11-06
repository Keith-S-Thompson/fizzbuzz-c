#include <stdio.h>
int main(void) {
    for (int i = 1; i <= 100; i ++) {
        printf(printf("%s%s",
                      i%3 ? "" : "Fizz",
                      i%5 ? "" : "Buzz") ? "\n" : "%d\n", i);
    }
}
