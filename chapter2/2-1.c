/* Exercise 2-1
 * Write a program to determine the ranges of char, short, int,
 * and long variables, both signed and unsigned, by printing appropriate
 * values from standard headers and by direct computation. Harder if you
 * compute them: determine the ranges of the various floating-point types.
 */

#include <stdio.h>
#include <limits.h>

int main()
{
    /* Char */
    printf("Signed char: \nMinimum: %d\nMaximum: %d", SCHAR_MIN, SCHAR_MAX);

    printf("\n\nUnsigned char: \nMaximum: %u", UCHAR_MAX);

    /* Short */
    printf("\n\nSigned short: \nMinimum: %d\nMaximum: %d", SHRT_MIN, SHRT_MAX);

    printf("\n\nUnsigned short: \nMaximum: %u", USHRT_MAX);

    /* Int */
    printf("\n\nSigned int: \nMinimum: %d\nMaximum: %d", INT_MIN, INT_MAX);

    printf("\n\nUnsigned int: \nMaximum: %u", UINT_MAX);

    /* Long */
    printf("\n\nSigned long: \nMinimum: %ld\nMaximum: %ld", LONG_MIN, LONG_MAX);

    printf("\n\nUnsigned int: \nMaximum: %u", ULONG_MAX);
    return 0;
}
