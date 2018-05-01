#include <stdio.h>
int main(void) {
    for (int x = 0; x <= 10; x ++) {
        for (int y = 0; y <= 9; y ++) {
            if (x == 0 && y == 0) {
                continue;
            }
            int printed = 0;
            if ((x + y) % 3 == 0) {
                fputs("Fizz", stdout);
                printed = 1;
            }
            if (y == 0 || y == 5) {
                fputs("Buzz", stdout);
                printed = 1;
            }
            if (!printed) {
                x && printf("%d", x);
                y && putchar(y%10 + '0') || putchar('0');
            }
            putchar('\n');
            if (x == 10 && y == 0) {
                break;
            }
        }
    }
}
