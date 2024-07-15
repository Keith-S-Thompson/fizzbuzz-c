#include <stdio.h>

static const char *line(int i) {
    switch (i % 15) {
        case 3: case 6: case 9: case 12: return "Fizz";
        case 0: case 5: case 10: return "FizzBuzz" + (4*!!(i%15));
        default: 
            static char s[3];
            s[0] = '0' + i / 10;
            s[1] = '0' + i % 10;
            return s + (i<10);
    }
}

int main(void) {
    for (int i = 1; i <= 100; i ++) {
        puts(line(i));
    }
}
