#include <stdio.h>
int main(void) {
    FILE **f = 2+(FILE*[6]){ tmpfile(), stdout };
    char *s[] = { "Fizz", "Buzz", (char[3]){0}, "\n" };
    for (int i = 1; i <= 100; i ++) {
        s[2][0] = (i < 9 ? i : i/10) + '0';
        s[2][1] =  i < 9 ? 0 : i%10  + '0';
        f[0] = f[i % 3 ? -2 : -1];
        f[1] = f[i % 5 ? -2 : -1];
        f[2] = f[f[0] == f[-1] || f[1] == f[-1] ? -2 : -1];
        f[3] = f[-1];
        for (int j = 0; j < 4; j ++) {
            fputs(s[j], f[j]);
        }
    }
}
