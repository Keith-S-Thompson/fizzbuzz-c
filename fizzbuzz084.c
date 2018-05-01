#include <stdio.h>

int main(void) {
    const char *format[] = {
        "FizzBuzz\n", "%d\n",   "%d\n",
        "Fizz\n",     "%d\n",   "Buzz\n",
        "Fizz\n",     "%d\n",   "%d\n",
        "Fizz\n",     "Buzz\n", "%d\n",
        "Fizz\n",     "%d\n",   "%d\n" };
    int i = 1;
    switch (i % 15) do {
        for (int j = 0; j < 5;  j++) { printf(format[i%15], i); i++; }
        case 1:
        for (int j = 0; j < 10; j++) { printf(format[i%15], i); i++; }
    } while(i < 100);
}
