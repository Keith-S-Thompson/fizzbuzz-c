#include <stdio.h>

enum return_target { zero, one, two };

static struct stack_frame {
    int lo;
    int hi;
    enum return_target ret;
} stack[100];
static int sp = -1;

static void dump_stack(void) {
    printf("Stack: sp=%d", sp);
    for (int i = 0; i <= sp; i ++) {
        printf(" { %d %d %d }", stack[i].lo, stack[i].hi, stack[i].ret);
    }
    putchar('\n');
}

#define CALL(target, lo_, hi_, ret_) \
    do { \
        /* printf(">>> In CALL(lo_=%d, hi_=%d, ret_=%d)\n", lo_, hi_, ret_); */ \
        sp ++; \
        stack[sp].lo = lo_; \
        stack[sp].hi = hi_; /* printf("    In CALL, hi_=%d, stack[%d].hi = %d\n", hi_, sp, stack[sp].hi); */ \
        stack[sp].ret = ret_; \
        /* dump_stack(); */ \
        goto target; \
    } while (0)

#define RETURN \
    do { \
        const enum return_target ret = stack[sp].ret; \
        sp --; \
        switch (ret) { \
            case zero: goto ZERO; \
            case one:  goto ONE; \
            case two:  goto TWO; \
        } \
    } while (0)

int main(void) {
    // printf(">>> CALL(FIZZBUZZ, %d, %d, %d)\n", 1, 100, zero);
    CALL(FIZZBUZZ, 1, 100, zero);
    ZERO:
    return 0;

    FIZZBUZZ:
    // printf(">>> FIZZBUZZ: sp=%d (%d, %d, %d)\n", sp, stack[sp].lo, stack[sp].hi, stack[sp].ret);
    // dump_stack();
    if (stack[sp].lo == stack[sp].hi) {
        if (stack[sp].lo % 15 == 0) {
            puts("FizzBuzz");
        }
        else if (stack[sp].lo % 3 == 0) {
            puts("Fizz");
        }
        else if (stack[sp].lo % 5 == 0) {
            puts("Buzz");
        }
        else {
            printf("%d\n", stack[sp].lo);
        }
    }
    else {
        const int lo1 = stack[sp].lo, hi1 = stack[sp].hi, mid1 = (lo1 + hi1) >> 1;
        CALL(FIZZBUZZ, lo1, mid1, one);
        ONE:;
        const int lo2 = stack[sp].lo, hi2 = stack[sp].hi, mid2 = (lo2 + hi2) >> 1;
        CALL(FIZZBUZZ, mid2+1, hi2, two);
        TWO:;
    }
    RETURN;
}
