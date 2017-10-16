#include <stdio.h>
#include <setjmp.h>
int main(void) {
    jmp_buf jb[7];
    volatile int j = 0;
    setjmp(jb[0]);
    volatile int i = 1;
    if (j == 0) setjmp(jb[1]);
    if (j == 1 && i > 100) longjmp(jb[6], 0);
    if (j == 1 && i % 15 == 0) longjmp(jb[4], 0);
    if (j == 1 && i % 3 == 0) longjmp(jb[2], 0);
    if (j == 1 && i % 5 == 0) longjmp(jb[3], 0);
    if (j == 1) printf("%d\n", i);
    if (j == 1) longjmp(jb[5], 0);
    if (j == 0) setjmp(jb[2]);
    if (j == 1) puts("Fizz");
    if (j == 1) longjmp(jb[5], 0);
    if (j == 0) setjmp(jb[3]);
    if (j == 1) puts("Buzz");
    if (j == 1) longjmp(jb[5], 0);
    if (j == 0) setjmp(jb[4]);
    if (j == 1) puts("FizzBuzz");
    if (j == 0) setjmp(jb[5]);
    i ++;
    if (j == 1) longjmp(jb[1], 0);
    if (j == 0) setjmp(jb[6]);
    j ++;
    if (j  < 2) longjmp(jb[0], 0);
}
