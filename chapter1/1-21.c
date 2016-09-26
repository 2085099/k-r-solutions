/* Exercise 1-21
 * Write a program entab that replaces strings of blanks
 * by the minimum number of tabs and blanks to achieve the
 * same spacing. Use the same tab stops as for detab. When
 * either a tab or a single blank would suffice to reach a
 * tab stop, which should be given preference?
 */

#define TABSTOP 8 /* Width of tab */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int c, pos, blanks, tabs;
    pos = 1;
    blanks = 0;
    tabs = 0;

    while ((c = getchar()) != EOF){

            if (c == ' '){
                if((pos % TABSTOP) != 0)
                    ++blanks;
                else
                {
                    blanks = 0;
                    ++tabs;
                }
            }

            else{
                for( ; tabs > 0 ; --tabs)
                    putchar('\t');
                if( c == '\t')
                    blanks = 0;
                else
                    for( ; blanks > 0; --blanks)
                        putchar(' ');

                putchar(c);

                if(c == '\n')
                    pos = 0;
                else if ( c == '\t')
                    pos = pos + ( TABSTOP - (pos - 1) % TABSTOP) - 1;
            }
    ++pos;
    }
    return 0;
}
