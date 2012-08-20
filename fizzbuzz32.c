#include <stdio.h>
#include <string.h>
int main(void) {
    char output[900] = "";
    for (int i = 18; i < 900; i += 27) {
        strcpy(output + i, "Fizz");
    }
    for (int i = 36; i < 900; i += 45) {
        strcat(output + i, "Buzz");
    }
    for (int i = 0; i < 900; i += 9) {
        if (!output[i]) {
            sprintf(output + i, "%d", i/9+1);
        }
    }
    for (int i = 0; i < 900; i += 9) {
        puts(output + i);
    }
    return 0;
}
