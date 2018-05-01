#include <stdio.h>
int main(void) {
    for (int i = 1; i <= 100; i ++) {
        switch (3&19142723>>i%017*2) {
            case 0: printf("%d\n", i); break;
            case 1: puts("Fizz");      break;
            case 2: puts("Buzz");      break;
            case 3: puts("FizzBuzz");  break;
        }
    }
}
