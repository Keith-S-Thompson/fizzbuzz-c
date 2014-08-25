#include <stdio.h>
#include <string.h>
int main(void) {
    for (int i = 1; i <= 100; i ++) {
        char format[11] = "";
        strcat(format, i % 3 ? "%.0s" : "%s");
        strcat(format, i % 5 ? "%.0s" : "%s");
        strcat(format, format[7]  ? "%d\n" : "\n");
        printf(format, "Fizz", "Buzz", i);
    }
}
