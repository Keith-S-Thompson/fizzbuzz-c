#include <stdio.h>
int main(void) {
    for (int i = 1; i <= 100; i ++) {
        printf(i % 15 == 0 ? "%s%s\n" :
               i %  3 == 0 ? "%s%.0s\n" :
               i %  5 == 0 ? "%.0s%s\n" :
                             "%.0s%.0s%d\n",
               "Fizz", "Buzz", i);
    }
}
