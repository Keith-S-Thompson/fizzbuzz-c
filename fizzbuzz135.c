#include <stdio.h>
#include <string.h>

int main(void) {
    const char *const F = "FizzBuzz\n",
               *const f = "Fizz\n",
               *const b = "Buzz\n",
               *const d = "%d\n",
               *format[105] = {F,d,d,f,d,b,f,d,d,f,b,d,f,d,d};
    for (const char **f = format+15; f < format+100; f+=15) {
        memcpy(f, f-15, 15*sizeof*format);
    }

    int i = 1;
    switch (i % 15) {
        case 11: do { printf(format[i], i); i++;
        case 12:      printf(format[i], i); i++;
        case 13:      printf(format[i], i); i++;
        case 14:      printf(format[i], i); i++;
        case 0:       printf(format[i], i); i++;
        case 1:       printf(format[i], i); i++;
        case 2:       printf(format[i], i); i++;
        case 3:       printf(format[i], i); i++;
        case 4:       printf(format[i], i); i++;
        case 5:       printf(format[i], i); i++;
        case 6:       printf(format[i], i); i++;
        case 7:       printf(format[i], i); i++;
        case 8:       printf(format[i], i); i++;
        case 9:       printf(format[i], i); i++;
        case 10:      printf(format[i], i); i++;
                 } while(i < 100);
    }
}
