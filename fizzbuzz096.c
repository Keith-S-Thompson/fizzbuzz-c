%:include <stdio.h>

static void func0(int n) <% printf("%d\n", n); ??>
static void func1(int n) <% puts("Fizz"); %>
static void func2(int n) ??< puts("Buzz"); ??>
static void func3(int n) ??< puts("FizzBuzz"); %>
static void (*const p<::>)(int) = ??< func0, func1, func2, func3 %>;

int main(void) ??<
    for (int i = 1; i <= 100; i ++) <%
        (!(i%5)<<1??'!(i%3))??(p:>(i);
    %>
%>
