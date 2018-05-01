#define _POSIX_C_SOURCE 199309L

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sched.h>

static int lines_printed = 0;
static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

static void try(int status) {
    if (status != 0) {
        exit(EXIT_FAILURE);
    }
}

static void *thread_routine(void *arg) {
    const int i = *(int*)arg;
    while (1) {
        try(pthread_mutex_lock(&mutex));
        if (lines_printed == i - 1) {
            if      (i % 15 == 0) puts("FizzBuzz");
            else if (i %  3 == 0) puts("Fizz");
            else if (i %  5 == 0) puts("Buzz");
            else                  printf("%d\n", i);
            lines_printed ++;
            free(arg);
            try(pthread_mutex_unlock(&mutex));
            pthread_exit(NULL);
        }
        else {
            try(pthread_mutex_unlock(&mutex));
        }
        sched_yield();
    }
}

static void launch_thread(int i, pthread_t *thread) {
    int *iptr = malloc(sizeof *iptr);
    if (iptr == NULL) {
        exit(EXIT_FAILURE);
    }
    *iptr = i;
    try(pthread_create(thread, NULL, thread_routine, iptr));
}

int main(void) {
    pthread_t threads[100];
    for (int i = 100; i >= 1; i --) {
        launch_thread(i, &threads[i-1]);
    }
    for (int i = 1; i <= 100; i ++) {
        try(pthread_join(threads[i-1], NULL));
    }
}
