#include <stdio.h>
#include <math.h>

/*
 * In principle, we could compute a value that indicates what to
 * print for each line by fitting a 99th-degree real polynomial to
 * the 100 data points.  Since the output repeats in a cyle of 15
 * (using the same value for lines on which the number is printed),
 * it's easier to fit a 14th-degree polynomial to 15 data points.
 *
 * http://www.xuru.org/rt/PR.asp can fit a polynomial of up to 10th
 * degree for a given set of data points, which is not quite enough.
 * The result, when rounded to the nearest integer, was correct
 * except for an input of 0, which yielded approximately -178 rather
 * than 3.
 *
 * The use of pow() to compute integer powers is admittedly
 * inefficient.
 */

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
