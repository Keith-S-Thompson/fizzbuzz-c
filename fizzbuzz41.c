#include <stdio.h>
int main(void) {
    for (int i = 1; i <= 100; i ++) {
        char s[4];
        sprintf(s, "%d", i);
        int three = 3*5*!(i%3);
        int five  = 3*5*!(i%5);
        printf("%.*s", three, "Fizz");
        printf("%.*s", five, "Buzz");
        printf("%.*s", 3*5*!(three+five), s);
        putchar('\n');
    }
    return 0;
}
