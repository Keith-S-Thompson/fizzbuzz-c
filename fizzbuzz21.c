#include <stdio.h>

const char *format[] = {
    "FizzBuzz\n", "%d\n",   "%d\n",
    "Fizz\n",     "%d\n",   "Buzz\n",
    "Fizz\n",     "%d\n",   "%d\n",
    "Fizz\n",     "Buzz\n", "%d\n",
    "Fizz\n",     "%d\n",   "%d\n" };

int main(void) {
    int i = 1;
    switch (i % 15) {
        case 11: do { printf(format[i%15], i); i++;
        case 12:      printf(format[i%15], i); i++;
        case 13:      printf(format[i%15], i); i++;
        case 14:      printf(format[i%15], i); i++;
        case 0:       printf(format[i%15], i); i++;
        case 1:       printf(format[i%15], i); i++;
        case 2:       printf(format[i%15], i); i++;
        case 3:       printf(format[i%15], i); i++;
        case 4:       printf(format[i%15], i); i++;
        case 5:       printf(format[i%15], i); i++;
        case 6:       printf(format[i%15], i); i++;
        case 7:       printf(format[i%15], i); i++;
        case 8:       printf(format[i%15], i); i++;
        case 9:       printf(format[i%15], i); i++;
        case 10:      printf(format[i%15], i); i++;
                 } while(i < 100);
    }
    return 0;
}

