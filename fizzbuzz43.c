#include <stdio.h>
int main(void) {
    char format[] = "%d\n%d\nFizz\n%d\nBuzz\nFizz\n%d\n%d\nFizz\nBuzz\n%d\nFizz\n%d\n%d\nFizzBuzz\n";
    for (int i = 1; i <= 100; i += 15) {
        if (i == 91) {
            format[40] = '\0';
        }
        printf(format, i, i+1, i+3, i+6, i+7, i+10, i+12, i+13);
    }
}
