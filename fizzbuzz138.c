#include <stdio.h>

static char s[10] = "FizzBuzzzz";

static int span(int i) {
    switch (i % 15) {
        case 3: case 6: case 9: case 12: return 0x04;
        case 5: case 10: return 0x44;
        case 0: return 0x08;
        default: 
            s[8] = '0' + i / 10;
            s[9] = '0' + i % 10;
            if (i < 10) return 0x91; else return 0x82;
    }
}

int main(void) {
    for (int i = 1; i <= 100; i ++) {
        const int sp = span(i);
        printf("%.*s\n", sp & 15, s + (sp >> 4));
    }
}
