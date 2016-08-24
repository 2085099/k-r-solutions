/* Exercise 1-9
*  Write a program to copy its input to its output,
*  replacing each string of one or more blanks by a single blank.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int c, lastc;

    c = 0;
    lastc = c;

    while ((c = getchar()) != EOF){
            if (c != ' '){ /* If character is not blank then print*/
                putchar(c);
            }

            if (c == ' '){ /* If character is blank, and the last char is not blank, print char */
                if (lastc != c){
                    putchar(c);
                }
            }
            lastc = c;
    }
    return 0;
}
