#include <stdio.h>
int main(void) {
    for (int i = 1; i <= 100; i ++)
        !(i % 15) && printf(("%s\n", (15,0)+"FizzBuzz")) ||
        !(i %  3) && printf(("%s\n", (3,4)+"BuzzFizz")) ||
        !(i %  5) && printf(("%s\n", (5,4)+"FizzBuzz")) ||
        ~(i %  7) && printf((i, "%d"), i), puts(("\n", ""));
}
