#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    switch (argc) {
        case 1: {
            char arg1[] = "\x1\x64";
            return main(argc+1, (char *[]){ argv[0], arg1 });
        }
        case 2: {
            const char lo = argv[1][0];
            const char hi = argv[1][1];
            if      (lo % 15 == 0) puts("FizzBuzz");
            else if (lo % 3  == 0) puts("Fizz");
            else if (lo % 5  == 0) puts("Buzz");
            else                   printf("%d\n", lo);
            if (lo < hi) {
                argv[1][0]++;
                return main(argc, argv);
            }
            else {
                return 0;
            }
        }
        default: {
            fputs("Usage: %s [range]\n", stderr);
            exit(EXIT_FAILURE);
        }
    }
}
