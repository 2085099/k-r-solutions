/* Exercise 2-6
 * Write a function setbits(x,p,n,y) that returns x with the n
 * bits that begin at position p set to the rightmost n bits of
 * y, leaving the other bits unchanged
 */

#include <stdio.h>
#include <stdlib.h>

unsigned setbits(unsigned x, int p, int n, int y);
int main()
{
	printf("%u\n", setbits(100, 2, 3, 5));

    return 0;
}

unsigned setbits(unsigned x, int p, int n, int y){

    unsigned a, b, mask;

    /* Mask the bits we want and shift to desired position */
    a = (~0 << n) | ~(~0 << (p + 1 - n));

    /* Applying this mask to x */
    a &= x;

    /* n bits at the right most position of y */
    b =y & ~(~0 << n);

    /* Left shift the bits by position p using (p+1-n) */
    b = b << (p + 1 - n);

    /* Set bits */
    return a | b;
    }
