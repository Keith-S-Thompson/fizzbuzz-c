#define _POSIX_C_SOURCE 199309L

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void die(char *message) {
    fprintf(stderr, "%s\n",  message);
    exit(EXIT_FAILURE);
}

void *thread_routine(void *arg) {
    const int i = *(int*)arg;
    if (i % 15 == 0) {
        return "FizzBuzz";
    }
    else if (i % 3 == 0) {
        return "Fizz";
    }
    else if (i % 5 == 0) {
        return "Buzz";
    }
    else {
        static char result[4];
        sprintf(result, "%d", i);
        return result;
    }
}

char *line(int i) {
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
        puts(line(i));
    }

    return 0;
}
