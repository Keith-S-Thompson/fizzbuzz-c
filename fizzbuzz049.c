#include <stdio.h>
#include <ctype.h>
#define PUTCHAR(c) (((c) ? putchar : isdigit)(c))
int main(void) {
    for (int i = 1; i <= 100; i ++) {
        PUTCHAR(!(i % 3) * 'F' |
                 (i % 3 && i % 5 == 0) * 'B' |
                 (i % 3 && i % 5 && i < 10) * (i + '0') |
                 (i % 3 && i % 5 && i > 9)  * (i / 10 + '0'));
        PUTCHAR(!(i % 3) * 'i' |
                 (i % 3 && !(i % 5)) * 'u' |
                 (i % 3 && i % 5 && i >= 10) * (i % 10 + '0'));
        PUTCHAR((!(i % 3) || !(i % 5)) * 'z');
        PUTCHAR((!(i % 3) || !(i % 5)) * 'z');
        PUTCHAR(!(i % 15) * 'B');
        PUTCHAR(!(i % 15) * 'u');
        PUTCHAR(!(i % 15) * 'z');
        PUTCHAR(!(i % 15) * 'z');
        PUTCHAR('\n');
    }
}
