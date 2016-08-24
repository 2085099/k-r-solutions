/* Exercise 1-14
* Write a program to print a histogram of the
* frequencies of different characters in its input.
*/

#include <stdio.h>

#define TOTALCHARS 128 /* Number of possible ASCII characters */

int main() {

    int nchars[TOTALCHARS], c, i, j;

    for (i = 0; i < TOTALCHARS; ++i){ /* Set all array character values to zero */
        nchars[i] = 0;
    }

    while((c = getchar()) != EOF) /* Increase frequency of character in array */
        ++nchars[c];

    for (i = 0; i < TOTALCHARS;++i){
        putchar(i);
        for (j = 0; j<nchars[i]; ++j){
            putchar('*');


        }
        putchar('\n');
    }
return 0;

}
