#include <stdio.h>
int main(void) {
_10:; int i = 1;
_20:  if (i > 100) goto _150;
_30:  if (i % 15 == 0) goto _120;
_40:  if (i % 3 == 0) goto _80;
_50:  if (i % 5 == 0) goto _100;
_60:  printf("%d\n", i);
_70:  goto _130;
_80:  puts("Fizz");
_90:  goto _130;
_100: puts("Buzz");
_110: goto _130;
_120: puts("FizzBuzz");
_130: i = i + 1;
_140: goto _20;
_150:;}
