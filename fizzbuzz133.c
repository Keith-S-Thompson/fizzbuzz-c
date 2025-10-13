#include <stdio.h>
#include <threads.h>

struct s {
    int i;
    const char *s;
};

#define MILLION 1000000LL
#define BILLION 1000000000LL

static void msleep(int milliseconds) {
    long long nanoseconds = milliseconds * MILLION;
    const struct timespec how_long = {
        .tv_sec  = nanoseconds / BILLION,
        .tv_nsec = nanoseconds % BILLION
    };
    thrd_sleep(&how_long, NULL);
}

static int line(void* arg) {
    const struct s argument = *(struct s*)arg;
    msleep(30 * argument.i);
    argument.s ? puts(argument.s) : printf("%d\n", argument.i);
    return 0;
}

int main(void) {
    thrd_t threads[100];
    struct s arguments[100];

    for (int i = 15; i <= 100; i += 15) {
        arguments[i-1] = (struct s){.i = i, .s = "FizzBuzz"};
        thrd_create(&threads[i-1], line, &arguments[i-1]);
    }
    for (int i = 3; i <= 100; i += 3) if (i % 5) {
        arguments[i-1] = (struct s){.i = i, .s = "Fizz"};
        thrd_create(&threads[i-1], line, &arguments[i-1]);
    }
    for (int i = 5; i <= 100; i += 5) if (i % 3) {
        arguments[i-1] = (struct s){.i = i, .s = "Buzz"};
        thrd_create(&threads[i-1], line, &arguments[i-1]);
    }
    for (int i = 1; i <= 100; i ++) if (i % 3 && i % 5) {
        arguments[i-1] = (struct s){.i = i, .s = NULL};
        thrd_create(&threads[i-1], line, &arguments[i-1]);
    }

    for (int i = 99; i >= 0; i --) {
        thrd_join(threads[i], NULL);
    }
}
