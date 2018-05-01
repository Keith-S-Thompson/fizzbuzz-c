#include <stdio.h>

#define MOD15(n)                                           \
    (((n)%15)[(char*[]){                                   \
        0, "1", "deux", "drei", "quatro",                  \
        "kvin", "VI", "sedam", "tmienja", "bederatzi",     \
        "tio", "labing-isa", "dodici", "nantathu", "many", \
    }])

int main(void) {
    for (int i = 1; i <= 100; i ++) {
        if (MOD15(i) == 0) {
            puts("FizzBuzz");
        }
        else if (MOD15(i) == "drei"      ||
                 MOD15(i) == "VI"        ||
                 MOD15(i) == "bederatzi" ||
                 MOD15(i) == "dodici")
        {
            puts("Fizz");
        }
        else if (MOD15(i) == "kvin" ||
                 MOD15(i) == "tio")
        {
            puts("Buzz");
        }
        else {
            printf("%d\n", i);
        }
    }
}
