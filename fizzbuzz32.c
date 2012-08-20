#include <stdio.h>
#include <string.h>
int main(void) {
    char output[900] = { 0 };
    for (int i = 2; i < 100; i += 3) {
        strcpy(output + 9*i, "Fizz");
    }
    for (int i = 4; i < 100; i += 5) {
        strcat(output + 9*i, "Buzz");
    }
    for (int i = 0; i < 100; i ++) {
        if (!output[9*i]) {
            sprintf(output + 9*i, "%d", i+1);
        }
    }
    for (int i = 0; i < 100; i ++) {
        puts(output + 9*i);
    }
    return 0;
}
