/* Exercise 2-9
 * In a two's complement number system, x &.= (x-1)
 * deletes the rightmost l-bit in x. Explain why.
 * Use this observation to write a faster version of bitcount.
 */

#include <stdio.h>
#include <stdlib.h>

int bitcount(unsigned x);
int main()
{
	printf("%d\n", bitcount(50));

    return 0;
}

int bitcount(unsigned x)
{
    int b;

    /* x = x & (x-1) deletes the last bit */
    for (b = 0; x!= 0; x &= x-1)
        ++b;

    return b;
}

