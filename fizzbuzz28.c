#include <stdio.h>
int main(void) {
    const char *const s[] = { NULL, "Fizz", "Buzz", "FizzBuzz" };
    for (int i = 1; i <= 100; i ++) {
        const int x = !(i%3) + (!(i%5)<<1);
        s[x] ? puts(s[x]) : printf("%d\n", i);
    }
    return 0;
}
