#include <stdio.h>
int main(void) {
    char *lines[100] = { 0 }, nums[162], *cursor = nums;
    const struct { char *s; int n; } dat[] = { "Fizz", 3, "Buzz", 5, "FizzBuzz", 15 };
    for (int i = 0; i < 3; i ++) {
        for (int j = dat[i].n-1; j < 100; j += dat[i].n) {
            lines[j] = dat[i].s;
        }
    }
    for (int i = 0; i < 100; i ++) {
        lines[i] || (lines[i] = cursor += 3) && sprintf(lines[i], "%d", i+1);
    }
    for (int i = 0; i < 100; i ++) {
        puts(lines[i]);
    }
}
