#include <stdio.h>
#include <stdint.h>
int main(void) {
    for(uint16_t i=18561;(i&127)<=100;i+=18561)(i&49152)==49152&&(i&=~
    49152),(i&14336)==10240&&(i&=~14336),(i&1920)==1920&&(i&=~1920),(!
    (i&1920))&&(puts("FizzBuzz"),1)||(!(i&49152))&&(puts("Fizz"),1)||(
    !(i&14336))&&(puts("Buzz"),1)||printf("%u\n",i&127);
}
