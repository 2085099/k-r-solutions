/* Exercise 7-9
 * Functions like isupper can be implemented to
 * save space or to save time. Explore both possibilities
 */

/* Macro saving time as it is readily available */
#define isupper(c)((c) >= 'A' && (c) <= 'Z')

#include <stdio.h>
#include <stdlib.h>

int misupper(char c);

int main()
{
    int macro = isupper('Q');

    printf("The character in question is %suppercase", (macro == 1) ? "" : "not ");
    return 0;
}

/* Function saves space. Unlike a macro, it is not directly loaded onto the final program */

int misupper(char c){
    return c >= 'A' && c <='Z';
}
