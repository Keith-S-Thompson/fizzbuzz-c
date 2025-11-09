#define ONE '/'/'/'
#define ZERO ONE-ONE
#define TWO ONE+ONE
#define THREE ONE+ONE+ONE
#define FIVE TWO+THREE
#define TEN FIVE+FIVE
#define FIFTEEN TEN+FIVE
#define THIRTY FIFTEEN+FIFTEEN
#define ONE_HUNDRED THIRTY+THIRTY+THIRTY+TEN

#include <stdio.h>
int main(void) {
    for (int i = ONE; i <= ONE_HUNDRED; i ++) {
        if (i % (FIFTEEN) == ZERO) {
            puts("FizzBuzz");
        }
        else if (i % (THREE) == ZERO) {
            puts("Fizz");
        }
        else if (i % (FIVE) == ZERO) {
            puts("Buzz");
        }
        else {
            printf("%d\n", i);
        }
    }
}
