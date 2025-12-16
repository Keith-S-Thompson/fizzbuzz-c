#include <stdio.h>
int main(void) {
    for (int i = 1; i <= 100; i ++)
        !(i % 15) && printf(("%s\n", (4,0)+"FizzBuzz")) ||
        !(i %  3) && printf(("%s\n", (0,4)+"BuzzFizz")) ||
        !(i %  5) && printf(("%s\n", (0,4)+"FizzBuzz")) ||
        printf((i, "%d"), i), puts(("\n", ""));
}
