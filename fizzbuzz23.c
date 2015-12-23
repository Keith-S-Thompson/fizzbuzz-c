#include <stdio.h>
#include <string.h>
int main(void) {
    char line[100][9];
    for (int i = 1; i <= 100; i ++ ) {
        sprintf(line[i-1], "%d", i);
    }
    for (int i = 3; i <= 100; i += 3) {
        strcpy(line[i-1], "Fizz");
    }
    for (int i = 5; i <= 100; i += 5) {
        strcpy(line[i-1], "Buzz");
    }
    for (int i = 15; i <= 100; i += 15) {
        strcpy(line[i-1], "FizzBuzz");
    }
    for (int i = 1; i <= 100; i ++) {
        puts(line[i-1]);
    }
}
