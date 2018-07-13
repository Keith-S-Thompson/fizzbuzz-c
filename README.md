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

This project contains, so far, 105 different C implementations of
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

* [fizzbuzz001.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz001.c)
  Straightforward solution.
* [fizzbuzz002.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz002.c)
  Don't Repeat Yourself, remember whether we printed anything.
* [fizzbuzz003.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz003.c)
  Similar to fizzbuzz002, but uses `ftell()` to detect whether anything was printed.  This version fails if stdout is not seekable.
* [fizzbuzz004.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz004.c)
  Brute force.
* [fizzbuzz005.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz005.c)
  Use the value returned by `printf` to detect whether anything was printed.
* [fizzbuzz006.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz006.c)
  Index into a two-dimensional array of pointers to strings.
* [fizzbuzz007.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz007.c)
  Reduce the body of the loop to a single convoluted expression statement using short-circuit `&&` and `||`.
* [fizzbuzz008.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz008.c)
  Abuse of the `?:` conditional operator.
* [fizzbuzz009.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz009.c)
  Similar, but using variables to remember whether `i` is a multiple of 3 and/or 5.
* [fizzbuzz010.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz010.c)
  Build an array of 100 function pointers, then traverse it (does not scale well).
* [fizzbuzz011.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz011.c)
  Use a function that returns a pointer to the appropriate function.
* [fizzbuzz012.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz012.c)
  Similar, but use two functions returning function pointers.
* [fizzbuzz013.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz013.c)
  Another array of function pointers, but only 4 this time, indexed by a number computed from i.
* [fizzbuzz014.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz014.c)
  Similar to fizzbuzz005, but adding abuse of short-circuit `||`.
* [fizzbuzz015.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz015.c)
  Use a `switch` statement.
* [fizzbuzz016.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz016.c)
  Replace the outer loop by gratuitous use of recursion.
* [fizzbuzz017.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz017.c)
  Replace the outer loop by gratuitous use of recursion with divide-and-conquer.
* [fizzbuzz018.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz018.c)
  Twist the logic around a bit and obfuscate.
* [fizzbuzz019.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz019.c)
  Loop unrolling.
* [fizzbuzz020.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz020.c)
  Duff's device (no, really!).
* [fizzbuzz021.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz021.c)
  Duff's device and an array of pointers to format strings.
* [fizzbuzz022.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz022.c)
  Use an array of 15 function pointers.
* [fizzbuzz023.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz023.c)
  Use a two-dimensional array of characters.
* [fizzbuzz024.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz024.c)
  Simple string processing.
* [fizzbuzz025.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz025.c)
  Use printf's "%n" conversion specifier and a little tricky logic.
* [fizzbuzz026.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz026.c)
  Manipulate the tens and units digits separately.
* [fizzbuzz027.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz027.c)
  Gratuitous use of pthreads.
* [fizzbuzz028.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz028.c)
  Another tricky way to determine what to print.
* [fizzbuzz029.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz029.c)
  Based on fizzbuzz029, but taking advantage of the fact that excess arguments to printf are ignored.
* [fizzbuzz030.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz030.c)
  Based on fizzbuzz030, but more terse, using a compound literal.
* [fizzbuzz031.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz031.c)
  More abuse of operators.
* [fizzbuzz032.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz032.c)
  Use a fixed-size one-dimensional char array.
* [fizzbuzz033.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz033.c)
  Track i%3 and i%5 in separate variables without using division.
* [fizzbuzz034.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz034.c)
  Use a wrapper function to perform the loop.
* [fizzbuzz035.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz035.c)
  Like fizzbuzz034, but recursive.
* [fizzbuzz036.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz036.c)
  Another brute-force approach, similar to fizzbuzz004.c but using a lookup table.
* [fizzbuzz037.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz037.c)
  A variant of fizzbuzz036.c, encoding the lookup table in white space.
* [fizzbuzz039.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz039.c)
  Call main() recursively.
* [fizzbuzz040.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz040.c)
  Call main() recursively with a single argument string representing the range.
* [fizzbuzz041.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz041.c)
  Control the output via the printf format string.
* [fizzbuzz042.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz042.c)
  Use the result of an inner printf to control an outer printf; abuse of conditional operator.
* [fizzbuzz043.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz043.c)
  Print 15 lines at a time, modifying the format string for the final iteration.
* [fizzbuzz044.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz044.c)
  Ugly games with printf format string.
* [fizzbuzz045.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz045.c)
  Even uglier games with printf format string.
* [fizzbuzz046.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz046.c)
  A terser version of fizzbuzz024.c.
* [fizzbuzz047.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz047.c)
  Build each line a character at a time.
* [fizzbuzz048.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz048.c)
  Build each line a character at a time using obfuscated arithmetic.
* [fizzbuzz049.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz049.c)
  Print each line a character at a time.
* [fizzbuzz050.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz050.c)
  Like fizzbuzz036.c, but more obfuscated.
* [fizzbuzz051.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz051.c)
  Like fizzbuzz050.c, but with a smaller lookup table.
* [fizzbuzz052.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz052.c)
  Math.
* [fizzbuzz053.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz053.c)
  Based on fizzbuzz004.c; so obvious I should have done it sooner.
* [fizzbuzz054.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz054.c)
  Just in case fizzbuzz053.c wasn't verbose enough.
* [fizzbuzz055.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz055.c)
  Finite state machine.
* [fizzbuzz056.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz056.c)
  Finite state machine, done the old fashioned way.
* [fizzbuzz057.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz057.c)
  Finite state machine, now even more obfuscated.
* [fizzbuzz058.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz058.c)
  Linked list of format structures.
* [fizzbuzz059.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz059.c)
  fizzbuzz058.c was too legible.
* [fizzbuzz060.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz060.c)
  Like fizzbuzz059.c, but relative offsets avoid the need for a pointer to the first element.
* [fizzbuzz061.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz061.c)
  Scramble and unscramble.
* [fizzbuzz062.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz062.c)
  Relatively straightforward use of ?: operator.
* [fizzbuzz063.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz063.c)
  This one works only if identical string literals occupy the same storage (it fails with tcc).
* [fizzbuzz064.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz064.c)
  Abuse of multi-character constants (works only if they have distinct values, which is not guaranteed) (it fails with tcc).
* [fizzbuzz065.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz065.c)
  You can write BASIC in any language.
* [fizzbuzz066.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz066.c)
  A few macros can make the code much clearer.
* [fizzbuzz067.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz067.c)
  Compound literal.
* [fizzbuzz068.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz068.c)
  Threads.
* [fizzbuzz069.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz069.c)
  Cheat.  Fails if `expected-output.txt` is not available.
* [fizzbuzz070.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz070.c)
  Based on fizzbuzz020.c, using Duff's Device.  Use printf for all lines, and shuffle the case labels.
* [fizzbuzz071.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz071.c)
  Based on fizzbuzz066.c but with more macros.
* [fizzbuzz072.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz072.c)
  More straightforward loop unrolling inspired by Duff's Device, with macros for brevity.
* [fizzbuzz073.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz073.c)
  Based on fizzbuzz023.c, using a two-dimensional array of characters.
* [fizzbuzz074.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz074.c)
  Inspired by fizzbuzz054.c, but print a bit at a time (assumes an ASCII-based character set).
* [fizzbuzz075.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz075.c)
  Like fizzbuzz074.c, but using 4 bits per character with a lookup table.
* [fizzbuzz076.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz076.c)
  Encode the data as a large integer, use GMP to extract it.
* [fizzbuzz077.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz077.c)
  Don't divide, just count.
* [fizzbuzz078.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz078.c)
  Like fizzbuzz077.c, but just use one 16-bit variable.
* [fizzbuzz079.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz079.c)
  Brute force with printf.
* [fizzbuzz080.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz080.c)
  Iterate over an array of lines.
* [fizzbuzz081.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz081.c)
  Search for the message in memory; depends on undefined behavior and luck.
* [fizzbuzz082.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz082.c)
  Some arithmetic and bit twiddling.
* [fizzbuzz083.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz083.c)
  Based on fizzbuzz082.c with an array of function pointers and backwards indexing.
* [fizzbuzz084.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz084.c)
  Based on fizzbuzz021.c, Duff's device with partial loop re-rolling of the unrolled loop.
* [fizzbuzz085.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz085.c)
  Simple yet convoluted logic.
* [fizzbuzz086.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz086.c)
  Print unconditionally to file handles that may or may not be open, ignoring errors.
* [fizzbuzz087.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz087.c)
  More preprocessor abuse.
* [fizzbuzz088.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz088.c)
  Compute the correct character for each position.
* [fizzbuzz089.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz089.c)
  Like fizzbuzz088.c, but without the confusing nested loop.
* [fizzbuzz090.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz090.c)
  Use an array of integers.
* [fizzbuzz091.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz091.c)
  Like fizzbuzz090.c, but using an array of characters (assumes an ASCII-based character set).
* [fizzbuzz092.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz092.c)
  Do it all in the for loop.
* [fizzbuzz093.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz093.c)
  Inspired by fizzbuzz-polyglot fizzbuzz.f66, emulating Fortran arithmetic IF.
* [fizzbuzz094.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz094.c)
  Replace all flow control by setjmp/longjmp.
* [fizzbuzz095.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz095.c)
  Function pointers.
* [fizzbuzz096.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz096.c)
  fizzbuzz083.c with digraphs and trigraphs.
* [fizzbuzz097.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz097.c)
  Print everything, but not all to the same place.
* [fizzbuzz098.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz098.c)
  Like fizzbuzz097.c but with arrays.
* [fizzbuzz099.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz099.c)
  Build the output in a 2D array by columns.
* [fizzbuzz100.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz100.c)
  Build the output in a 2D array, initialized in a more interesting order.
* [fizzbuzz101.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz101.c)
  Use strcat -- or not.
* [fizzbuzz102.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz102.c)
  Use sprintf, then clean up.
* [fizzbuzz103.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz103.c)
  More obscure operator usage
* [fizzbuzz104.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz104.c)
  Similar to fizzbuzz103.c, but slightly different logic
* [fizzbuzz105.c](https://github.com/Keith-S-Thompson/fizzbuzz-c/blob/master/fizzbuzz105.c)
  Randomly approach the correct output
