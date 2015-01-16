#include <stdio.h>
int main(void) {
    for (int i = 0; i < 100; i ++) {
        switch ((i)["[[][\"][[]\"[][['"
                    "[[][\"][[]\"[][['"
                    "[[][\"][[]\"[][['"
                    "[[][\"][[]\"[][['"
                    "[[][\"][[]\"[][['"
                    "[[][\"][[]\"[][['"
                    "[[][\"][[]\"[][['"])
        {
            case '[':  printf("%d\n", i+1); break;
            case ']':  puts("Fizz");        break;
            case '"':  puts("Buzz");        break;
            case '\'': puts("FizzBuzz");    break;
        }
    }
}
