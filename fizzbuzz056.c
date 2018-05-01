#include <stdio.h>

int main(void) {
    int i = 1;
    goto s11;
    s00: puts("FizzBuzz"); i++;  goto s11;
    s01: puts("Fizz");     i++;  goto s12;
    s02: puts("Fizz");     i++;  goto s13;
    s03: puts("Fizz");     i++;  goto s14;
    s04: puts("Fizz");     i++;  goto s10;
    s10: puts("Buzz");     i++;  if (i > 100) goto s99; goto s21;
    s11: printf("%d\n",    i++); goto s22;
    s12: printf("%d\n",    i++); goto s23;
    s13: printf("%d\n",    i++); goto s24;
    s14: printf("%d\n",    i++); goto s20;
    s20: puts("Buzz");     i++;  goto s01;
    s21: printf("%d\n",    i++); goto s02;
    s22: printf("%d\n",    i++); goto s03;
    s23: printf("%d\n",    i++); goto s04;
    s24: printf("%d\n",    i++); goto s00;
    s99:;
}
