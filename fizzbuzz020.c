#include <stdio.h>
int main(void) {
    int i = 1;
    switch (i % 15) {
        case 11: do { printf("%d\n",    i++);
        case 12:      puts("Fizz");     i++;
        case 13:      printf("%d\n",    i++);
        case 14:      printf("%d\n",    i++);
        case 0:       puts("FizzBuzz"); i++;
        case 1:       printf("%d\n",    i++);
        case 2:       printf("%d\n",    i++);
        case 3:       puts("Fizz");     i++;
        case 4:       printf("%d\n",    i++);
        case 5:       puts("Buzz");     i++;
        case 6:       puts("Fizz");     i++;
        case 7:       printf("%d\n",    i++);
        case 8:       printf("%d\n",    i++);
        case 9:       puts("Fizz");     i++;
        case 10:      puts("Buzz");     i++;
                 } while(i < 100);
    }
}
