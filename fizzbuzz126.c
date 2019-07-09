#include <stdio.h>
#include <setjmp.h>
int main(void) {
    jmp_buf jb[7];
    volatile int j = 0;
    setjmp(jb[0]);
    volatile int i = 1;
    if (!j) setjmp(jb[1]);
    j && i > 100 && (longjmp(jb[6], 0), 0);
    j && !(i % 15) && (longjmp(jb[4], 0), 0);
    j && !(i % 3) && (longjmp(jb[2], 0), 0);
    j && !(i % 5) && (longjmp(jb[3], 0), 0);
    j && printf("%d\n", i);
    j && (longjmp(jb[5], 0), 0);
    if (!j) setjmp(jb[2]);
    j && puts("Fizz");
    j && (longjmp(jb[5], 0), 0);
    if (!j) setjmp(jb[3]);
    j && puts("Buzz");
    j && (longjmp(jb[5], 0), 0);
    if (!j) setjmp(jb[4]);
    j && puts("FizzBuzz");
    if (!j) setjmp(jb[5]);
    i ++;
    j && (longjmp(jb[1], 0), 0);
    if (!j) setjmp(jb[6]);
    j++ < 1 && (longjmp(jb[0], 0), 0);
}
