#define BEGIN {
#define BUZZ "Buzz"
#define DO
#define ELSE );} else {
#define ELSEIF );} else if (
#define END }
#define ENDFOR }
#define ENDIF );}
#define EQUALS ==
#define FIFTEEN 15
#define FIVE 5
#define FIZZ "Fizz"
#define FIZZBUZZ "FizzBuzz"
#define FIZZBUZZ71 main
#define FOR(i, lo, hi) for (int i = lo; i <= hi; i ++) {
#define HUNDRED *0144
#define IF if (
#define IS (void)
#define MOD %
#define ONE 1
#define PRINT puts(
#define PRINTINTEGER printf("%d\n", 
#define PROGRAM int
#define THEN ) {
#define THREE 3
#define ZERO 0

#include <stdio.h>

PROGRAM FIZZBUZZ71 IS
BEGIN
    FOR (I, ONE, ONE HUNDRED) DO
        IF I MOD FIFTEEN EQUALS ZERO THEN
            PRINT FIZZBUZZ
        ELSEIF I MOD THREE EQUALS ZERO THEN
            PRINT FIZZ
        ELSEIF I MOD FIVE EQUALS ZERO THEN
            PRINT BUZZ
        ELSE
            PRINTINTEGER I
        ENDIF
    ENDFOR
END
