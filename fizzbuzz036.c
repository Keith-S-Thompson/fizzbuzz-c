#include <stdio.h>
int main(void) {
    for (int i = 1; i <= 100; i ++) {
        switch ((i-1)["ddfdbfddfbdfddFddfdbfddfb"
                      "dfddFddfdbfddfbdfddFddfdb"
                      "fddfbdfddFddfdbfddfbdfddF"
                      "ddfdbfddfbdfddFddfdbfddfb"])
        {
            case 'd': printf("%d\n", i); break;
            case 'f': puts("Fizz");      break;
            case 'b': puts("Buzz");      break;
            case 'F': puts("FizzBuzz");  break;
        }
    }
}
