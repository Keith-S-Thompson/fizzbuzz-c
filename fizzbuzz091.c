#include <stdio.h>
int main(void) {
    const unsigned char lines[100] =
        "\1\2F\4BF\7\10FB\13F\15\16Z"
        "\20\21F\23BF\26\27FB\32F\34\35Z"
        "\37 F\"BF%&FB)F+,Z"
        "./F1BF45FB8F:;Z"
        "=>F@BFCDFBGFIJZ"
        "LMFOBFRSFBVFXYZ"
        "[\\F^BFabFB";
    for (int i = 0; i < sizeof lines; i ++) {
        lines[i] == 'F' && (puts("Fizz")||1ll) ||
        lines[i] == 'B' && (puts("Buzz")||1ll) ||
        lines[i] == 'Z' && (puts("FizzBuzz")||1ll) ||
        printf("%d\n", lines[i]);
    }
}
