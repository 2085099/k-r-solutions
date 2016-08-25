/* Exercise 1-20
 * Write a program detab that replaces tabs
 * in the input with the proper number of blanks
 * to space to the next tab stop. Assume a fixed
 * set of tab stops, say every n columns. Should n
 * be a variable or a symbolic parameter?
 */

#define TABSTOP 8 /* Width of tab */

#include <stdio.h>
#include <stdlib.h>

int detab(int pos);

int main()
{
    int c, pos;
    pos = 1;

    while ((c = getchar()) != EOF){

            /* NOTE: tabs are replaced with '-' */
            if (c == '\t'){
                pos = detab(pos); /* Detab and return position after detab */
            }

            else if (c == '\n'){
                putchar(c);
                pos = 1;
            }

            else{
                putchar(c);
                ++pos;
            }
    }
    return 0;
}

int detab(int pos){
    int posref;
    posref = TABSTOP - ((pos-1) % TABSTOP); /* Find the remaining amount of spaces
                                             * available in the tab */

    while (posref > 0){
        putchar('-');
        --posref;
        ++pos;
    }

    return pos;
}
