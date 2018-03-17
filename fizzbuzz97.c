#include <stdio.h>
int main(void) {
    FILE *nowhere = tmpfile();
    FILE *fizz, *buzz, *num, *newline;
    for (int i = 1; i <= 100; i ++) {
        fizz = i % 3 ? nowhere : stdout;
        buzz = i % 5 ? nowhere : stdout;
        num = fizz == stdout || buzz == stdout ? nowhere : stdout;
        newline = stdout;
        fputs("Fizz", fizz);
        fputs("Buzz", buzz);
        fprintf(num, "%d", i);
        putc('\n', newline);
    }
}
