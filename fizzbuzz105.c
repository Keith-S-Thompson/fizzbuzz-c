#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int is_correct(int i, char *line) {
    if (i % 15 == 0) {
        return strcmp(line, "FizzBuzz") == 0;
    }
    else if (i % 3 == 0) {
        return strcmp(line, "Fizz") == 0;
    }
    else if (i % 5 == 0) {
        return strcmp(line, "Buzz") == 0;
    }
    else {
        char correct[5];
        sprintf(correct, "%d", i);
        return strcmp(line, correct) == 0;
    }
}

int main(void) {
    char output[100][9];
    int count = 0;
    while (count < 100) {
        for (int i = 1; i <= 100; i ++) {
            if (! is_correct(i, output[i-1])) {
                switch (rand() % 4) {
                    case 0:
                        strcpy(output[i-1], "FizzBuzz");
                        break;
                    case 1:
                        strcpy(output[i-1], "Fizz");
                        break;
                    case 2:
                        strcpy(output[i-1], "Buzz");
                        break;
                    case 3:
                        sprintf(output[i-1], "%d", i);
                        break;
                }
                if (is_correct(i, output[i-1])) {
                    count ++;
                }
            }
        }
    }
    for (int i = 1; i <= 100; i ++) {
        puts(output[i-1]);
    }
}
