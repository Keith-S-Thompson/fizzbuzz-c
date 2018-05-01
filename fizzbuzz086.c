#include <stdio.h>

static void update(FILE **f, int i) {
    fclose(stderr);
    f[0] = i % 3 == 0 ? stdout : stderr;
    f[1] = i % 5 == 0 ? stdout : stderr;
    f[2] = (i % 3 == 0 || i % 5 == 0) ? stderr : stdout;
    f[3] = stdout;
}

int main(void) {
    FILE *f[4];
    for (int i = 1; i <= 100; i ++) {
        update(f, i);
        fputs("Fizz", f[0]);
        fputs("Buzz", f[1]);
        fprintf(f[2], "%d", i);
        putc('\n', f[3]);
    }
}
