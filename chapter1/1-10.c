/* Exercise 1-10
* Write a Program to copy its input to its output,
* replacing each tab by t,each backspace by b, and each backslash by \.
* This makes tabs and backspaces visible in an unambiguous way.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int c;

    while ((c = getchar()) != EOF){
            if (c == '\t'){ /* If character is not blank then print*/
                putchar('\\t');
            }

            if (c == '\b'){ /* If character is blank, and the last char is not blank, print char */
                putchar('\\b');
            }

            if (c == '\\'){ /* If character is blank, and the last char is not blank, print char */
                putchar('\\\\');
            }

            if(c !='\t' && c !='\b' && c!= '\\')
                putchar(c);
    }
    return 0;
}
