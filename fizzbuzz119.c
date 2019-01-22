#include <stdio.h>
#include <math.h>

static double polynomial(long long n) {
    return - 4.956564401E-6 * pow(n, 10)
           + 3.717551624E-4 * pow(n, 9)
           - 1.204679872E-2 * pow(n, 8)
           + 2.209286235E-1 * pow(n, 7)
           - 2.52332041     * pow(n, 6)
           + 18.61544946    * pow(n, 5)
           - 89.05106853    * pow(n, 4)
           + 269.9378432    * pow(n, 3)
           - 489.974344     * pow(n, 2)
           + 472.8329881    * n
           - 178.0520294;
}

int main(void) {
    for (int i = 1; i <= 100; i ++) {
        switch ((int)round(polynomial(i%15))) {
            case -178: puts("FizzBuzz");  break;
            case 0:    puts("Buzz");      break;
            case 1:    puts("Fizz");      break;
            case 2:    printf("%d\n", i); break;
        }
    }
}
