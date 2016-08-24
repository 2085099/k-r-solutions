/* Exercise 1-8
*  Write a program to count blanks, tabs, and newlines.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int c, blanks, tabs, newlines;

    c = 0;
    blanks = 0;
    tabs = 0;
    newlines = 0;

    while ((c = getchar()) != EOF){
            if (c == ' '){
                ++blanks;
            }

            if (c == '\t'){
                ++tabs;
            }

            if (c == '\n'){
                ++newlines;
            }

    printf("Blanks: %d, Tabs: %d, Newlines: %d\n", blanks, tabs, newlines );

    }
    return 0;
}
