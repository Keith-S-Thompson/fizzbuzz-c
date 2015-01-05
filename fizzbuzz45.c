#include <stdio.h>
#include <string.h>
int main(void) {
    for (int i = 1; i <= 100; i ++) {
        char format[12];
        sprintf(format,
                "%%%ss%%%ss%s\n",
                i%3?".0":"",
                i%5?".0":"",
                i%3&&i%5?"%d":"");
        printf(format, "Fizz", "Buzz", i);
    }
}
