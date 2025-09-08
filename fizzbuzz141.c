#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void) {
    char *lines[101] = { 0 };
    srand(time(NULL));
    int count = 0;
    while (count < 100) {
        const int i = rand() % 100 + 1;
        if (lines[i] == NULL) {
            if (i % 15 == 0) {
                lines[i] = "FizzBuzz";
            }
            else if (i % 3 == 0) {
                lines[i] = "Fizz";
            }
            else if (i % 5 == 0) {
                lines[i] = "Buzz";
            }
            else {
                lines[i] = malloc(3);
                sprintf(lines[i], "%d", i);
            }
            count ++;
        }
    }
    for (int i = 1; i < sizeof lines / sizeof lines[0]; i ++) {
        puts(lines[i]);
    }
}
