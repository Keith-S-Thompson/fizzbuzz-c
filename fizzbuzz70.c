#include <stdio.h>
int main(void) {
    int i = 1;
    switch (i % 15) {
        case 11: do { printf("%d\n",       i++);
        case 14:      printf("Fizz\n",     i++);
        case 5:       printf("%d\n",       i++);
        case 15:      printf("%d\n",       i++);
        case 4:       printf("FizzBuzz\n", i++);
        case 1:       printf("%d\n",       i++);
        case 12:      printf("%d\n",       i++);
        case 2:       printf("Fizz\n",     i++);
        case 6:       printf("%d\n",       i++);
        case 3:       printf("Buzz\n",     i++);
        case 10:      printf("Fizz\n",     i++);
        case 7:       printf("%d\n",       i++);
        case 13:      printf("%d\n",       i++);
        case 8:       printf("Fizz\n",     i++);
        case 9:       printf("Buzz\n",     i++);
                 } while(i < 100);
    }
}
