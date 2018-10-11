#include <stdio.h>

#define IF(cond,le,eq,gt) do { switch(((cond) < 0 ? -1 : (cond) == 0 ? 0 : 1)) \
                          { case -1: goto le; case 0: goto eq; case 1: goto gt; } } while (0)

int main(void) {
    int i = 1;
    L1: IF (i % 15, L3, L2, L3);
    L2: puts("FizzBuzz");
    goto L8;
    L3: IF (i % 3, L5, L4, L5);
    L4: puts("Fizz");
    goto L8;
    L5: IF (i % 5, L7, L6, L7);
    L6: puts("Buzz");
    goto L8;
    L7: printf("%d\n", i);
    L8: i ++; IF (i - 101, L1, L9, L1);
    L9:;
}
