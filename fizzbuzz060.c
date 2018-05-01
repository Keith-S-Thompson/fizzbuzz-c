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
        [h] = { "Fizz\n", +d },
        [d] = { "Fizz\n", +c },
        [n] = { "%d\n", +p },
        [o] = { "%d\n", +e },
        [l] = { "Buzz\n", +o },
        [i] = { "%d\n", -e },
        [g] = { "Fizz\n", -l },
        [j] = { "%d\n", -b },
        [p] = { "FizzBuzz\n", -a },
        [b] = { "%d\n", -g },
        [e] = { "%d\n", +g },
        [m] = { "%d\n", -a },
        [a] = { "Buzz\n", +o },
        [c] = { "%d\n", -c },
        [k] = { "Fizz\n", +a },
    }+n;
    for (int i = 1; i <= 100; i ++) {
        printf(format->format, i);
        format += format->next;
    }
}
