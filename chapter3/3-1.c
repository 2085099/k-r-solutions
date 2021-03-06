/* Exercise 3-1
 * Our binary search makes two tests inside the loop,
 * when one would suffice (at the price of more tests outside.)
 * Write a version with only one test inside the loop and
 * measure the difference in runtime.
 */

#include <stdio.h>
#include <stdlib.h>

int binsearch(int x,int v[],int n);

int main()
{
    int sortedNums[]={1,2,6,7,10,13,29,46,47,55,62};
    printf("%d",binsearch(13,sortedNums,10));
    return 0;
}

int binsearch(int x,int v[],int n)
{
    int low, high, mid;

    low=0;
    high=n-1;
    mid = ( low + high ) / 2;

    while(low < high && x != v[mid])
    {
        if( x < v[mid])
            high = mid -1;

        else
            low = mid + 1;
        mid = (low + high) / 2;
    }

    if(x==v[mid])
        return mid; /* match */
    else
        return -1; /* no match */
}
