Most of these programs are (intended to be) 100% portable C, conforming
to the ISO C99 and C11 standards.

A few of them are non-portable, depending on implementation-defined
features, or even on undefined behavior.

Many of them rely on C99's ability to define a variable in a `for` loop.

The `verify` script is a Bourne shell script, so it will only work
on systems that provide the Bourne shell.  It uses a number of
UNIX-specific commands, and it assumes that the program's output
can be compared for binary equivalence (using the `cmp` command)
to the expected output.  A system such as Windows with a different
text file representation would break that assumption.

Here I document the non-portable programs.  Any programs not
appearing on this list are intended to be portable.  There may be
some non-portabilities that I've missed.

* `fizzbuzz003.c`  
  This works only if standard input is seekable.  The `verify`
  script ensures that it's run that way.  If you compile and run it
  manually, it will fail with `exit(EXIT_FAILURE)`, probably with an
  error message like `ftell: Illegal seek`.

* `fizzbuzz025.c`  
  This relies on `printf` to support the `"%n"` conversion specifier.
  This is not an optional feature; any conforming hosted
  C implementation must support it.  But there is at least one C
  runtime library implementation (the one used on Android) that doesn't
  support it because the maintainers consider it to be too dangerous.

* `fizzbuzz027.c`  
  This relies on the POSIX threads as specified in the `<pthread.h>`
  header.  This is obviously not portable to non-POSIX systems.
  It relies on the `verify` script to invoke the compiler properly.
  See also `fizzbuzz133.c`, which uses ISO C `<threads.h>`.

* `fizzbuzz063.c`  
  This assumes that identical string literals are stored in the
  same memory location.  For example, the string literal `"drei"`
  occurs twice in the source code.  If the compiler doesn't store them
  both in the same location, the test will fail.  It is unspecified
  whether identical string literals are stored in the same location;
  the behavior can vary across different compilers, and is not required
  to be documented.

* `fizzbuzz064.c`  
  A multi-character constant such as `'10'` is of type `int` and
  has an implementation-defined value.  This program assumes that
  distinct multi-character constants such as `'10'` and `'11'` have
  distinct values.  This is not guaranteed by the language.

* `fizzbuzz068.c`  
  Like `fizzbuzz027.c`, this relies on POSIX threads, and on the `verify`
  script to invoke the compiler properly.

* `fizzbuzz069.c`  
  This relies on the existence of a file called `expected-output.txt`.

* `fizzbuzz076.c`  
  This relies on the non-standard GnuMP library and the `<gmp.h>` header,
  and on the `verify` script to link it properly.

* `fizzbuzz078.c`  
  This relies on the existence of the type `uint16_t`, declared in
  `<stdint.h>`.  The header is required to exist in any conforming
  C99 or later implementation, but the type `uint16_t` will not be
  defined unless there is an integer type that meets its requirements,
  and a conforming implementation is not required to have such a type.

* `fizzbuzz081.c`  
  This is horribly non-portable.  It searches memory near the entry
  point for the `main()` function for contents of a string literal.
  Futhermore, it converts the value of `main` (a function pointer)
  to `char*`, which has undefined behavior (gcc incorrectly says that
  it's forbidden by ISO C).

* `fizzbuzz105.c`  
  This sets up a 2-dimensional array of characters and *randomly*
  fills it in with correct values.  If `rand()` misbehaves, it's
  possible that the entire array will never be filled in correctly
  and the program might never terminate.  The standard places few
  requirements on the behavior of `rand()`.

* `fizzbuzz106.c`  
  Inspired by an early IOCCC winner, this is just  
  `#include </dev/stdin>`  
  It relies on the existence of `/dev/stdin`, and on the `verify`
  script to feed it the correct input.

* `fizzbuzz107.c`  
  This relies on the `verify` script to invoke the compiler so that
  the macros are predefined, and on the compiler to accept command-line
  arguments to predefine macros.

* `fizzbuzz114.c`  
  This requires an ASCII-compatible character set.  In practice,
  it's likely to work with anything other than EBCDIC.

* `fizzbuzz133.c`  
  This requires a C11 or higher implementation that supports
  `<threads.h>`, an optional feature.

* `fizzbuzz134.c`  
  This requires a preprocessor that supports the `__COUNTER__`
  predefined macro, a GNU C extension.
