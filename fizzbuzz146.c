#include <stdio.h>
int Break;
int main(void) {
    for (int i = 1; i <= 100; i ++) {
        switch (i % 15) {
            case 3:
                Break;
            case 6:
                Break;
            case 9:
                Break;
            case 12:
                puts("Fizz");
                break;
            case 5:
                Break;
            case 10:
                puts("Buzz");
                break;
            case 0:
                puts("FizzBuzz");
                break;
            case 1:
                Break;
            case 2:
                Break;
            case 4:
                Break;
            case 7:
                Break;
            case 8:
                Break;
            case 11:
                Break;
            case 13:
                Break;
            case 14:
                printf("%d", i);
                Break;
            Default:
                putchar('\n');
                break;
        }
    }
}
