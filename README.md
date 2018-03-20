FizzBuzz is a nearly trivial programming exercise, sometimes used in
job interviews to weed out candidates who say they can program but
really can't.

References:

* [Using FizzBuzz to Find Developers who Grok Coding](http://imranontech.com/2007/01/24/using-fizzbuzz-to-find-developers-who-grok-coding/) by Imran Ghory
* [Why Can't Programmers.. Program?](http://www.codinghorror.com/blog/2007/02/why-cant-programmers-program.html) by Jeff Atwood

The requirements are simple:

> Write a program that prints the numbers from 1 to 100. But for multiples
> of three print "Fizz" instead of the number and for the multiples of
> five print "Buzz". For numbers which are multiples of both three and
> five print "FizzBuzz".

Here's a straightforward implementation in C, similar to one I
wrote (on paper!) in a job interview of my own a few years ago.
(The problem statement didn't explicitly say what to print for numbers
that are multiples of both three and five, so I stated the assumption
explicitly as part of my solution.)

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

It requires a C compiler that accepts C99 or C11, or at least permits
declarations in `for` loop headers.  If you don't have such a compiler
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
solving*.  The entire program is only 18 lines (given the way I place
my curly braces), and nobody who knows C should have any difficulty
understanding what it does or modifying it correctly in the unlikely
event that maintenance is called for.

Still, it can be instructive to see how the program might be modified
to avoid the duplication.

It's easy enough to test whether `i` is a multiple of 3 just once,
and if so, print `"Fizz"`, and then to test whether it's a multiple
of 5, and if so, print `"Buzz"`.  But then you have to remember
whether you printed anything, and print the number itself *only*
if you haven't printed either `"Fizz"` or `"Buzz"` *or both* (and
then unconditionally print a new-line character).

And there are a number of other ways to solve the problem.

This project contains, so far, 98 different C implementations of
FizzBuzz, most of them deliberately silly, using various combinations
of the `?:` conditional operator, short-circuit `&&` and `||`, function
pointers, arrays of function pointers, arrays of arrays of function
pointers, gratuitous recursion, gratuitous divide-and-conquer, [Duff's
Device](http://en.wikipedia.org/wiki/Duff%27s_device), and outright
deliberate obfuscation.  One of them works only if the program's output
is redirected to a seekable file; it dies with an error message if
stdout is sent to a terminal.  Another works only on implementations
that support [Pthreads](http://en.wikipedia.org/wiki/Pthreads).
(The 2011 ISO C standard adds threads as an optional feature;
I haven't yet written a version that takes advantage of that.)
Yet another depends on undefined behavior and a certain amount
of blind luck.

Please do not use these programs as examples of good programming style.

* [fizzbuzz01.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz01.c)
  Straightforward solution.
* [fizzbuzz02.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz02.c)
  Don't Repeat Yourself, remember whether we printed anything.
* [fizzbuzz03.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz03.c)
  Similar to fizzbuzz02, but uses `ftell()` to detect whether anything was printed.  This version fails if stdout is not seekable.
* [fizzbuzz04.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz04.c)
  Brute force.
* [fizzbuzz05.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz05.c)
  Use the value returned by `printf` to detect whether anything was printed.
* [fizzbuzz06.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz06.c)
  Index into a two-dimensional array of pointers to strings.
* [fizzbuzz07.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz07.c)
  Reduce the body of the loop to a single convoluted expression statement using short-circuit `&&` and `||`.
* [fizzbuzz08.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz08.c)
  Abuse of the `?:` conditional operator.
* [fizzbuzz09.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz09.c)
  Similar, but using variables to remember whether `i` is a multiple of 3 and/or 5.
* [fizzbuzz10.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz10.c)
  Build an array of 100 function pointers, then traverse it (does not scale well).
* [fizzbuzz11.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz11.c)
  Use a function that returns a pointer to the appropriate function.
* [fizzbuzz12.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz12.c)
  Similar, but use two functions returning function pointers.
* [fizzbuzz13.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz13.c)
  Another array of function pointers, but only 4 this time, indexed by a number computed from i.
* [fizzbuzz14.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz14.c)
  Similar to fizzbuzz05, but adding abuse of short-circuit `||`.
* [fizzbuzz15.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz15.c)
  Use a `switch` statement.
* [fizzbuzz16.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz16.c)
  Replace the outer loop by gratuitous use of recursion.
* [fizzbuzz17.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz17.c)
  Replace the outer loop by gratuitous use of recursion with divide-and-conquer.
* [fizzbuzz18.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz18.c)
  Twist the logic around a bit and obfuscate.
* [fizzbuzz19.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz19.c)
  Loop unrolling.
* [fizzbuzz20.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz20.c)
  Duff's device (no, really!).
* [fizzbuzz21.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz21.c)
  Duff's device and an array of pointers to format strings.
* [fizzbuzz22.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz22.c)
  Use an array of 15 function pointers.
* [fizzbuzz23.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz23.c)
  Use a two-dimensional array of characters.
* [fizzbuzz24.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz24.c)
  Simple string processing.
* [fizzbuzz25.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz25.c)
  Use printf's "%n" conversion specifier and a little tricky logic.
* [fizzbuzz26.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz26.c)
  Manipulate the tens and units digits separately.
* [fizzbuzz27.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz27.c)
  Gratuitous use of pthreads.
* [fizzbuzz28.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz28.c)
  Another tricky way to determine what to print.
* [fizzbuzz29.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz29.c)
  Based on fizzbuzz29, but taking advantage of the fact that excess arguments to printf are ignored.
* [fizzbuzz30.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz30.c)
  Based on fizzbuzz30, but more terse, using a compound literal.
* [fizzbuzz31.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz31.c)
  More abuse of operators.
* [fizzbuzz32.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz32.c)
  Use a fixed-size one-dimensional char array.
* [fizzbuzz33.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz33.c)
  Track i%3 and i%5 in separate variables without using division.
* [fizzbuzz34.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz34.c)
  Use a wrapper function to perform the loop.
* [fizzbuzz35.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz35.c)
  Like fizzbuzz34, but recursive.
* [fizzbuzz36.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz36.c)
  Another brute-force approach, similar to fizzbuzz04.c but using a lookup table.
* [fizzbuzz37.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz37.c)
  A variant of fizzbuzz36.c, encoding the lookup table in white space.
* [fizzbuzz39.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz39.c)
  Call main() recursively.
* [fizzbuzz40.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz40.c)
  Call main() recursively with a single argument string representing the range.
* [fizzbuzz41.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz41.c)
  Control the output via the printf format string.
* [fizzbuzz42.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz42.c)
  Use the result of an inner printf to control an outer printf; abuse of conditional operator.
* [fizzbuzz43.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz43.c)
  Print 15 lines at a time, modifying the format string for the final iteration.
* [fizzbuzz44.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz44.c)
  Ugly games with printf format string.
* [fizzbuzz45.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz45.c)
  Even uglier games with printf format string.
* [fizzbuzz46.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz46.c)
  A terser version of fizzbuzz24.c.
* [fizzbuzz47.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz47.c)
  Build each line a character at a time.
* [fizzbuzz48.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz48.c)
  Build each line a character at a time using obfuscated arithmetic.
* [fizzbuzz49.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz49.c)
  Print each line a character at a time.
* [fizzbuzz50.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz50.c)
  Like fizzbuzz36.c, but more obfuscated.
* [fizzbuzz51.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz51.c)
  Like fizzbuzz50.c, but with a smaller lookup table.
* [fizzbuzz52.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz52.c)
  Math.
* [fizzbuzz53.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz53.c)
  Based on fizzbuzz04.c; so obvious I should have done it sooner.
* [fizzbuzz54.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz54.c)
  Just in case fizzbuzz53.c wasn't verbose enough.
* [fizzbuzz55.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz55.c)
  Finite state machine.
* [fizzbuzz56.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz56.c)
  Finite state machine, done the old fashioned way.
* [fizzbuzz57.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz57.c)
  Finite state machine, now even more obfuscated.
* [fizzbuzz58.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz58.c)
  Linked list of format structures.
* [fizzbuzz59.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz59.c)
  fizzbuzz58.c was too legible.
* [fizzbuzz60.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz60.c)
  Like fizzbuzz59.c, but relative offsets avoid the need for a pointer to the first element.
* [fizzbuzz61.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz61.c)
  Scramble and unscramble.
* [fizzbuzz62.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz62.c)
  Relatively straightforward use of ?: operator.
* [fizzbuzz63.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz63.c)
  This one works only if identical string literals occupy the same storage (it fails with tcc).
* [fizzbuzz64.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz64.c)
  Abuse of multi-character constants (works only if they have distinct values, which is not guaranteed) (it fails with tcc).
* [fizzbuzz65.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz65.c)
  You can write BASIC in any language.
* [fizzbuzz66.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz66.c)
  A few macros can make the code much clearer.
* [fizzbuzz67.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz67.c)
  Compound literal.
* [fizzbuzz68.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz68.c)
  Threads.
* [fizzbuzz69.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz69.c)
  Cheat.  Fails if `expected-output.txt` is not available.
* [fizzbuzz70.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz70.c)
  Based on fizzbuzz20.c, using Duff's Device.  Use printf for all lines, and shuffle the case labels.
* [fizzbuzz71.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz71.c)
  Based on fizzbuzz66.c but with more macros.
* [fizzbuzz72.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz72.c)
  More straightforward loop unrolling inspired by Duff's Device, with macros for brevity.
* [fizzbuzz73.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz73.c)
  Based on fizzbuzz23.c, using a two-dimensional array of characters.
* [fizzbuzz74.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz74.c)
  Inspired by fizzbuzz54.c, but print a bit at a time (assumes an ASCII-based character set).
* [fizzbuzz75.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz75.c)
  Like fizzbuzz74.c, but using 4 bits per character with a lookup table.
* [fizzbuzz76.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz76.c)
  Encode the data as a large integer, use GMP to extract it.
* [fizzbuzz77.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz77.c)
  Don't divide, just count.
* [fizzbuzz78.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz78.c)
  Like fizzbuzz77.c, but just use one 16-bit variable.
* [fizzbuzz79.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz79.c)
  Brute force with printf.
* [fizzbuzz80.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz80.c)
  Iterate over an array of lines.
* [fizzbuzz81.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz81.c)
  Search for the message in memory; depends on undefined behavior and luck.
* [fizzbuzz82.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz82.c)
  Some arithmetic and bit twiddling.
* [fizzbuzz83.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz83.c)
  Based on fizzbuzz82.c with an array of function pointers and backwards indexing.
* [fizzbuzz84.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz84.c)
  Based on fizzbuzz21.c, Duff's device with partial loop re-rolling of the unrolled loop.
* [fizzbuzz85.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz85.c)
  Simple yet convoluted logic.
* [fizzbuzz86.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz86.c)
  Print unconditionally to file handles that may or may not be open, ignoring errors.
* [fizzbuzz87.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz87.c)
  More preprocessor abuse.
* [fizzbuzz88.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz88.c)
  Compute the correct character for each position.
* [fizzbuzz89.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz89.c)
  Like fizzbuzz88.c, but without the confusing nested loop.
* [fizzbuzz90.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz90.c)
  Use an array of integers.
* [fizzbuzz91.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz91.c)
  Like fizzbuzz90.c, but using an array of characters (assumes an ASCII-based character set).
* [fizzbuzz92.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz92.c)
  Do it all in the for loop.
* [fizzbuzz93.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz93.c)
  Inspired by fizzbuzz-polyglot fizzbuzz.f66, emulating Fortran arithmetic IF.
* [fizzbuzz94.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz94.c)
  Replace all float control by setjmp/longjmp.
* [fizzbuzz95.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz95.c)
  Function pointers.
* [fizzbuzz96.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz96.c)
  fizzbuzz83.c with digraphs and trigraphs.
* [fizzbuzz97.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz97.c)
  Print everything, but not all to the same place.
* [fizzbuzz98.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz98.c)
  Like fizzbuzz97.c but with arrays.
