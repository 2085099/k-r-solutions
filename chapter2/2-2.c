/* Exercise 2-2
 * Write a loop equivalent to the for loop above without using &&
 * or ||
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, lim, c;

    lim = 10;

    char s[lim];
    i = 0;

    while (i < lim-1){
        if (((c=getchar()) != '\n')){
            if (c != EOF){
                s[i] = c;
                ++i;
            }
            else {
                break;
            }
        } else{
            break;
        }
    }
    s[i] = '\0'; /* Terminate array */

    return 0;
}
