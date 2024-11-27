extern int putchar(int ch);

static void putline(const char *s) {
    for (const char *p = s; *p != '\0'; p ++) {
        putchar(*p);
    }
    putchar('\n');
}

int main(void) {
    for (int i = 1; i <= 100; i ++) {
        if (i % 15 == 0) {
            putline("FizzBuzz");
        }
        else if (i % 3 == 0) {
            putline("Fizz");
        }
        else if (i % 5 == 0) {
            putline("Buzz");
        }
        else {
            if (i >= 10) putchar(i / 10 + '0');
            putchar(i % 10 + '0');
            putchar('\n');
        }
    }
}
