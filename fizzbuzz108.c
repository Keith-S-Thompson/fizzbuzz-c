#include <stdio.h>
int main(void) {
    for (int i = 1; i <= 100; i++) {
        printf("%.*s%.*s%.d\n", 4*!(i%3), "Fizz", 4*!(i%5), "Buzz", (i%3&&i%5)*i);
    }
}
