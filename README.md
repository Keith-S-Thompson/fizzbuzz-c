FizzBuzz is a nearly trivial programming exercise, sometimes used in
job interviews to weed out candidates who say they can program but
really can't.

References:

* [http://imranontech.com/2007/01/24/using-fizzbuzz-to-find-developers-who-grok-coding/](Using FizzBuzz to Find Developers who Grok Coding) by Imran Ghory
* [http://www.codinghorror.com/blog/2007/02/why-cant-programmers-program.html](Why Can't Programmers.. Program?) by Jeff Atwood

The requirements are simple:

> Write a program that prints the numbers from 1 to 100. But for multiples
> of three print "Fizz" instead of the number and for the multiples of
> five print "Buzz". For numbers which are multiples of both three and
> five print "FizzBuzz".

Here's a straightforward implementation in C, similar to one I wrote
(on paper!) in a recent job interview of my own.  (The problem
statement didn't explictly say what to print for numbers that are
multiples of both three and five, so I stated the assumption explicitly
as part of my solution.)

    #include <stdio.h>
    int main(void) {
        for (int i = 1; i <= 100; i ++) {
            if (i % 15 == 0) {
                puts("FizzBuzz");
            }
            else if (i % 3 == 0) {
                puts("Fizz");
            }
            else if (i % 5 == 0) {
                puts("Buzz");
            }
            else {
                printf("%d\n", i);
            }
        }
        return 0;
    }

Some notes on this solution:

It requires a C compiler that accepts C99, or at least permits
declarations in for loop headers.  If you don't have such a compiler
(`gcc -std=c99` works), you can change this:

        for (int i = 1; i <= 100; i ++) {

to this:

        int i;
        for (i = 1; i <= 100; i ++) {

It takes advantage of a small piece of mathematics that's not stated
in the problem, namely that a number is a multiple of both 3 and 5
if and only if it's a multiple of 15 -- and of course that you can
test whether a number is a multiple of some `N` using the `%` operator.

Some important pieces of information are stated twice.  In particular:

* The string `"Fizz"` appears twice, once by itself and once as part of `"FizzBuzz"`.
* Likewise for the string `"Buzz"`.
* The test for `i` being a multiple of 3 is effectively performed
  twice, once in the test `i % 3`, and once, indirectly, in the test
  `i % 15`.
* Likewise for the test for `i` being a multiple of 5.

These are violations of the DRY (["Don't Repeat
Yourself"](http://en.wikipedia.org/wiki/DRY)) principle.  For example,
if I wanted to change the program to print "Bizz" and "Buzz",
as in the [drinking game](http://en.wikipedia.org/wiki/Bizz_Buzz)
that inspired the problem, I'd have to change "Fizz" to "Bizz" in
two different places; similarly if I wanted to check for multiples
of 3 and 7 rather than 3 and 5.

For a problem of this trivial size, *none of these problems are worth
solving*.  The entire program is only 18 lines, and nobody who knows
C should have any difficulty understanding what it does or modifying
it correctly in the unlikely event that maintenance is called for.

Still, it can be instructive to see how the program might be modified
to avoid the duplication.

It's easy enough to test whether `i` is a multiple of 3 just once,
and if so, print `"Fizz"`, and then to test whether it's a multiple
of 5, and if so, print `"Buzz"`.  But then you have to remember
whether you printed anything, and print the number itself *only*
if you haven't printed either `"Fizz"` or `"Buzz"` *or both* (and
then unconditionally print a new-line character).

And there are a number of other ways to solve the problem.

This project contains, so far, 25 different C implementations of
FizzBuzz, most of them deliberately silly, using various combinations
of the `?:` conditional operator, short-circuit `&&` and `||`,
function pointers, arrays of function pointers, arrays of arrays of
function pointers, gratuitous recursion, gratuitous divide-and-conquer,
[Duff's Device](http://en.wikipedia.org/wiki/Duff%27s_device), and
outright deliberate obfuscation.  And one of them works only if the
program's output is redirected to a seekable file; it dies with an
error message if stdout is sent to a terminal.

Please do not use these programs as examples of good programming style.

* [fizzbuzz01.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz01.c)
  Straightforward solution
* [fizzbuzz02.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz02.c)
  Don't Repeat Yourself, remember whether we printed anything
* [fizzbuzz03.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz03.c)
  Similar to fizzbuzz02, but uses `ftell()` to detect whether anything was printed.  This version fails if stdout is not seekable.
* [fizzbuzz04.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz04.c)
  Brute force
* [fizzbuzz05.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz05.c)
  Use the value returned by `printf` to detect whether anything was printed
* [fizzbuzz06.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz06.c)
  Index into a two-dimensional array of pointers to strings
* [fizzbuzz07.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz07.c)
  Reduce the body of the loop to a single convoluted expression statement using short-circuit `&&` and `||`
* [fizzbuzz08.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz08.c)
  Abuse of the `?:` conditional operator
* [fizzbuzz09.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz09.c)
  Similar, but using variables to remember whether `i` is a multiple of 3 and/or 5
* [fizzbuzz10.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz10.c)
  Build an array of 100 function pointers, then traverse it (does not scale well)
* [fizzbuzz11.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz11.c)
  Use a function that returns a pointer to the appropriate function
* [fizzbuzz12.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz12.c)
  Similar, but use two functions returning function pointers
* [fizzbuzz13.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz13.c)
  Another array of function pointers, but only 4 this time, indexed by a number computed from i
* [fizzbuzz14.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz14.c)
  Similar to fizzbuzz05, but adding abuse of short-circuit `||`
* [fizzbuzz15.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz15.c)
  Use a `switch` statement
* [fizzbuzz16.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz16.c)
  Replace the outer loop by gratuitous use of recursion
* [fizzbuzz17.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz17.c)
  Replace the outer loop by gratuitous use of recursion with divide-and-conquer
* [fizzbuzz18.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz18.c)
  Twist the logic around a bit and obfuscate
* [fizzbuzz19.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz19.c)
  Loop unrolling
* [fizzbuzz20.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz20.c)
  Duff's device (no, really!)
* [fizzbuzz21.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz21.c)
  Duff's device and an array of pointers to format strings
* [fizzbuzz22.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz22.c)
  Use an array of 15 function pointers
* [fizzbuzz23.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz23.c)
  Use a two-dimensional array of characters
* [fizzbuzz24.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz24.c)
  Simple string processing
* [fizzbuzz25.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz25.c)
  Use printf's "%n" conversion specifier and a little tricky logic
* [fizzbuzz26.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz26.c)
  Manipulate the tens and units digits separately
* [fizzbuzz27.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz27.c)
  Gratuitous use of pthreads
