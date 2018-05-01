#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv) {
    switch (argc) {
        case 1: {
            return main(3, (char *[]){ argv[0], "1", "100" });
        }
        case 3: {
            const int lo = atoi(argv[1]);
            const int hi = atoi(argv[2]);
            if      (lo % 15 == 0) puts("FizzBuzz");
            else if (lo % 3  == 0) puts("Fizz");
            else if (lo % 5  == 0) puts("Buzz");
            else                   printf("%d\n", lo);
            if (lo < hi) {
                char arg1[4];
                sprintf(arg1, "%d", lo+1);
                return main(3, (char*[]){argv[0], arg1, argv[2]});
            }
            else {
                return 0;
            }
        }
        default: {
            fputs("Usage: %s [lo hi]\n", stderr);
            exit(EXIT_FAILURE);
        }
    }
}
