#include <stdio.h>

#define IF(cond,le,eq,gt) do { switch(((cond) < 0 ? -1 : (cond) == 0 ? 0 : 1)) \
                          { case -1: goto le; case 0: goto eq; case 1: goto gt; } } while (0)

int main(void) {
    for (int i = 1; i <= 100; i ++) {
        IF (i % 15, L19, L10, L19);
        L10: puts("FizzBuzz");
        goto L99;

        L19: IF (i % 3, L29, L20, L29);
        L20: puts("Fizz");
        goto L99;

        L29: IF (i % 5, L39, L30, L39);
        L30: puts("Buzz");
        goto L99;

        L39: printf("%d\n", i);

        L99:;
    }
}
