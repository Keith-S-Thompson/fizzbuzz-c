#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct FizzBuzz {
    void *impl;
};

struct FizzBuzz newFizzBuzz(int factor1, int factor2, const char *s1, const char *s2, int lo, int hi);
void invoke(struct FizzBuzz fb);
void destroyFizzBuzz(const struct FizzBuzz *fb);

int main(void) {
    const struct FizzBuzz fb = newFizzBuzz(3, 5, "Fizz", "Buzz", 1, 100);
    invoke(fb);
    destroyFizzBuzz(&fb);
}

struct impl {
    int factor1;
    int factor2;
    const char *s1;
    const char *s2;
    int lo;
    int hi;
};

struct FizzBuzz newFizzBuzz(int factor1, int factor2, const char *s1, const char *s2, int lo, int hi) {
    struct impl *impl = malloc(sizeof *impl);
    if (impl != NULL) {
        impl->factor1 = factor1;
        impl->factor2 = factor2;
        impl->s1 = s1;
        impl->s2 = s2;
        impl->lo = lo;
        impl->hi = hi;
    }
    return (struct FizzBuzz){.impl = impl};
}

void invoke(struct FizzBuzz fb) {
    const struct impl *impl = (struct impl*)fb.impl;
    for (int i = impl->lo; i <= impl->hi; i ++) {
        bool printed = false;
        if (i % impl->factor1 == 0) {
            fputs(impl->s1, stdout);
            printed = true;
        }
        if (i % impl->factor2 == 0) {
            fputs(impl->s2, stdout);
            printed = true;
        }
        if (!printed) {
            printf("%d", i);
        }
        putchar('\n');
    }
}

void destroyFizzBuzz(const struct FizzBuzz *fb) {
    free(fb->impl);
}
