#include <stdio.h>
char num[4];
char *output[3][2] = { { "", "Fizz" },
                       { "", "Buzz" },
                       { "", num } };
int main(void) {
    for (int i = 1; i <= 100; i ++) {
        int m3 = !(i%3);
        int m5 = !(i%5);
        sprintf(num, "%d", i);
        printf("%s%s%s\n",
               output[0][m3],
               output[1][m5],
               output[2][!m3&!m5]);
    }
    return 0;
}
