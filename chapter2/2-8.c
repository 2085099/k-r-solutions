/* Exercise 2-8
 * Write a function rightrot(x,n) that returns the
 * value of the integer x rotated to the right by n bit positions
 */

#include <stdio.h>
#include <stdlib.h>

unsigned rightrot(unsigned x, int n);
int main()
{
	printf("%u\n", rightrot(25000, 3));

    return 0;
}

unsigned rightrot(unsigned x, int n)
{
    while (n > 0) {
        /* If the last bit is 1, shift and add 1 to the front bit */
        if(x & 1)
            x = (x >> 1) | ~(~0U >> 1);
        /* If 0, simply shift and the first bit will be 0 */
        else
            x = x >> 1;
        --n;
    }
    return x;
}

