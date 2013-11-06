#include <stdio.h>
int main(void) {
    for (int i = 1; i <= 100; i ++) {
        switch (i%15) {
            case 0:
                puts("FizzBuzz");
                break;
            case 3: case 6: case 9: case 12:
                puts("Fizz");
                break;
            case 5: case 10:
                puts("Buzz");
                break;
            default:
                printf("%d\n", i);
                break;
        }
    }
}
