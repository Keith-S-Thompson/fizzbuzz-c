#include <stdio.h>
int main(void) {
    enum { a=012, b, c, d, e, f };
    struct format {
        const char *format;
        struct format *next;
    } formats[] = {
        [1] = { "Fizz\n",     &formats[6] },
        [d] = { "Fizz\n",     &formats[3] },
        [8] = { "%d\n",       &formats[c] },
        [2] = { "%d\n",       &formats[d] },
        [7] = { "%d\n",       &formats[2] },
        [b] = { "%d\n",       &formats[1] },
        [9] = { "FizzBuzz\n", &formats[7] },
        [e] = { "%d\n",       &formats[9] },
        [a] = { "Buzz\n",     &formats[b] },
        [4] = { "Fizz\n",     &formats[a] },
        [5] = { "Buzz\n",     &formats[0] },
        [0] = { "Fizz\n",     &formats[8] },
        [3] = { "%d\n",       &formats[5] },
        [6] = { "%d\n",       &formats[e] },
        [c] = { "%d\n",       &formats[4] },
    };
    struct format *format = formats+7;
    for (int i = 1; i <= 100; i ++) {
        printf(format->format, i);
        format = format->next;
    }
}
