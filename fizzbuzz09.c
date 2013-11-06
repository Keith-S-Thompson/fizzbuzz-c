#include <stdio.h>
int main(void) {
    for (int i = 1; i <= 100; i ++) {
        int m3 = !(i%3);
        int m5 = !(i%5);
        !(m3|m5)?printf("%d\n",i):puts(m3&m5?"FizzBuzz":m3?"Fizz":"Buzz");
    }
}
