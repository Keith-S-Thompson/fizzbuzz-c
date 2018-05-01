#include <stdio.h>

int main(void) {
    int i = 1;
    goto l7;
    l8: printf("Fizz\n",     i++); goto l1;
    l6: printf("Fizz\n",     i++); goto l2;
    l9: printf("%d\n",       i++); goto l8;
    lf: printf("%d\n",       i++); goto l6;
    lc: printf("Fizz\n",     i++); goto l0;
    la: printf("Buzz\n",     i++); if (i > 100) goto l4; goto lf;
    l7: printf("%d\n",       i++); goto l9;
    l2: printf("%d\n",       i++); goto l3;
    l0: printf("%d\n",       i++); goto l5;
    lb: printf("FizzBuzz\n", i++); goto l7;
    le: printf("Buzz\n",     i++); goto lc;
    l3: printf("%d\n",       i++); goto lb;
    l1: printf("%d\n",       i++); goto le;
    ld: printf("Fizz\n",     i++); goto la;
    l5: printf("%d\n",       i++); goto ld;
    l4:;
}
