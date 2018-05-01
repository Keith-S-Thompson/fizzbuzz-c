#include <stdio.h>
int main(void) {
    FILE *f = fopen("expected-output.txt", "r");
    int c;
    while ((c = fgetc(f)) != EOF) {
        putchar(c);
    }
    fclose(f);
}
