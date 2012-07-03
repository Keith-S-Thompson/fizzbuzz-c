#define _POSIX_C_SOURCE 199309L

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void die(char *message) {
    fprintf(stderr, "%s\n",  message);
    exit(EXIT_FAILURE);
}

struct dstring {
    char *str;
    bool allocated;
};

void *thread_routine(void *arg) {
    const int i = *(int*)arg;
    struct dstring *result = malloc(sizeof *result);
    if (result == NULL) {
        die("malloc failed");
    }
    if (i % 15 == 0) {
        *result = (struct dstring){ .str = "FizzBuzz",  .allocated = false };
    }
    else if (i % 3 == 0) {
        *result = (struct dstring){ .str = "Fizz",  .allocated = false };
    }
    else if (i % 5 == 0) {
        *result = (struct dstring){ .str = "Buzz",  .allocated = false };
    }
    else {
        char *str = malloc(4);
        if (str == NULL) {
            die("malloc failed");
        }
        sprintf(str, "%d", i);
        *result = (struct dstring){ .str = str, .allocated = true };
    }
    return result;
}

struct dstring *line(int i) {
    pthread_t thr;
    int result = pthread_create(&thr, NULL, thread_routine, &i);
    if (result != 0) {
        die("Error in pthread_create");
    }
    void *retval;
    result = pthread_join(thr, &retval);
    if (result != 0) {
        die("Error in pthread_create");
    }
    return retval;
}

int main(void) {
    for (int i = 1; i <= 100; i ++) {
        struct dstring *dline = line(i);
        puts(dline->str);
        if (dline->allocated) {
            free(dline->str);
        }
        free(dline);
    }

    return 0;
}
