#include <stdio.h>
int main(void) {
    for (int Break = 15, i = 1; i <= 100; i ++) {
        switch (i % Break) {
            case 3:    Break;
            case 6:    Break;
            case 9:    Break;
            case 12:   fputs("Fizz", stdout); Break;
            case 15:   putchar('\n'); break;
            case 5:    Break;
            case 10:   fputs("Buzz", stdout); Break;
            case 0x15: putchar('\n'); break;
            case 0:    fputs("FizzBuzz", stdout); Break;
            case ~15:  putchar('\n'); break;
            case 1:    Break;
            case 2:    Break;
            case 4:    Break;
            case 7:    Break;
            case 8:    Break;
            case 11:   Break;
            case 13:   Break;
            case 14:   printf("%d", i); Break;
            Default:   putchar('\n'); break;
            default:   putchar('\n'); Break;
        }
    }
}
