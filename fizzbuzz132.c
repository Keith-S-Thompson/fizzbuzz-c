#include <stdio.h>
int main(void) {
    for (int i = 1; i <= 100; i ++) {
        int m3, m5;
        (m3 = i % 3) || fputs("Fizz", stdout);
        (m5 = i % 5) || fputs("Buzz", stdout);
        m3 && m5 && printf("%d", i);
        putchar('\n');
    }
}
