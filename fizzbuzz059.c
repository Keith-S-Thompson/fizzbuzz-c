#include <stdio.h>
int main(void) {
    enum {
        k, o, h, n,
        e, c, l, g,
        a, b, d, p,
        m, f, i, j,
    };
    const struct format {
        const char *format;
        int next;
    } *format = (struct format[]) {
        [l] = { "Buzz\n", g },
        [h] = { "Fizz\n", m },
        [e] = { "%d\n", p },
        [b] = { "%d\n", h },
        [p] = { "FizzBuzz\n", n },
        [k] = { "Fizz\n", a },
        [c] = { "%d\n", k },
        [d] = { "Fizz\n", j },
        [m] = { "%d\n", e },
        [o] = { "%d\n", c },
        [g] = { "Fizz\n", o },
        [j] = { "%d\n", l },
        [n] = { "%d\n", i },
        [i] = { "%d\n", d },
        [a] = { "Buzz\n", b },
    }+n, *formats=format-n;
    for (int i = 1; i <= 100; i ++) {
        printf(format->format, i);
        format = formats+format->next;
    }
}
