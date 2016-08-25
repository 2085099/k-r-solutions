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
            if (c == '\t'){ 
                putchar('\\t');
            }

            if (c == '\b'){ 
                putchar('\\b');
            }

            if (c == '\\'){ 
                putchar('\\\\');
            }

            if(c !='\t' && c !='\b' && c!= '\\')
                putchar(c);
    }
    return 0;
}
