#include <stdio.h>
int main(void) {
    for (int i = 1; i <= 100; i ++) {
        printf((char*[]){"%d\n","Fizz\n","Buzz\n","FizzBuzz\n"}[!(i%3)+(!(i%5)<<1)],i);
    }
    return 0;
}
