#include <stdio.h>
#include <stdlib.h>

#define SIZE 60000
static char output[SIZE];

void store_char(char c) {
    output[rand() % SIZE] = c;
}

void store_string(const char *s) {
    for (int i = 0; s[i] != '\0'; i ++) {
        store_char(s[i]);
    }
}

int main(void) {
    srand(42);
    for (int i = 1; i <= 100; i ++) {
        if      (i % 15 == 0) store_string("FizzBuzz\n");
        else if (i %  3 == 0) store_string("Fizz\n");
        else if (i %  5 == 0) store_string("Buzz\n");
        else {
            if (i > 10) store_char('0' + i / 10);
            store_char('0' + i % 10);
            store_char('\n');
        }
    }
    store_char('\0');

    srand(42);

    while (1) {
        const char c = output[rand() % SIZE];
        if (c == '\0') break;
        putchar(c);
    }
}
