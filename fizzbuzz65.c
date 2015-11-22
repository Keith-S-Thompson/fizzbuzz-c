#include <stdio.h>
int main(void) {
int i = 1;
_10:  if (i > 100) goto _140;
_20:  if (i % 15 == 0) goto _110;
_30:  if (i % 3 == 0) goto _70;
_40:  if (i % 5 == 0) goto _90;
_50:  printf("%d\n", i);
_60:  goto _120;
_70:  puts("Fizz");
_80:  goto _120;
_90:  puts("Buzz");
_100: goto _120;
_110: puts("FizzBuzz");
_120: i = i + 1;
_130: goto _10;
_140: ; }
