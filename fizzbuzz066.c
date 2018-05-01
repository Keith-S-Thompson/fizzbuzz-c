#define PROGRAM(name) int name(void)
#define MOD %
#define FOR(i, lo, hi) for (int i = lo; i <= hi; i ++) {
#define DO
#define BEGIN {
#define END }
#define IF if (
#define THEN ) {
#define ELSEIF } else if (
#define ELSE } else {
#define ENDIF }
#define ENDFOR }
#define PRINT(s) puts(s);
#define PRINTINTEGER(i) printf("%d\n", i);

#include <stdio.h>

PROGRAM(main)
BEGIN
    FOR (I, 1, 100) DO
        IF I MOD 15 == 0 THEN
            PRINT("FizzBuzz")
        ELSEIF I MOD 3 == 0 THEN
            PRINT("Fizz")
        ELSEIF I MOD 5 == 0 THEN
            PRINT("Buzz")
        ELSE
            PRINTINTEGER(I)
        ENDIF
    ENDFOR
END
