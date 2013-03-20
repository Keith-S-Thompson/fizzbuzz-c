#include <stdio.h>
int main(void) {
    for (int i = 1; ; i += 15) {
        printf("%d\n%d\nFizz\n%d\nBuzz\nFizz\n%d\n%d\nFizz\nBuzz\n",
               i, i+1, i+3, i+6, i+7);
        if (i+10 > 100) break;
        printf("%d\nFizz\n%d\n%d\nFizzBuzz\n",
               i+10, i+12, i+13);
    }
    return 0;
}
