#include <stdio.h>
#define I printf("%d\n",i++);
#define F puts("Fizz");i++;
#define B puts("Buzz");i++;
#define Z puts("FizzBuzz");i++;
#define S s:
int main(void) {
    int i = 1;
    goto s;
    do { I F I I Z S I I F I B F I I F B } while (i < 100);
}
