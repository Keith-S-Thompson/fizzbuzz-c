#include <stdio.h>
int main(void) {
    for (int i = 1; ; i += 15) {
        printf("%d\n%d\n", i, i+1);
        puts("Fizz");
        printf("%d\n", i+3);
        puts("Buzz");
        puts("Fizz");
        printf("%d\n%d\n", i+6, i+7);
        puts("Fizz\nBuzz");
        if (i+10 > 100) break;
        printf("%d\n", i+10);
        puts("Fizz");
        printf("%d\n%d\n", i+12, i+13);
        puts("FizzBuzz");
    }
}
