/* Exercise 7-2
 * Write a program that will print arbitrary
 * input in a sensible way. As a minimum, it
 * should print non-graphic characters in octal
 * or hexadecimal according to local custom,
 * and break long text lines.
 */

#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>

#define CHARWIDTH 50

int main()
{
    int c, width;

    while ((c = getchar()) != EOF){
        if (c == '\n' || width > CHARWIDTH){
            width = 0;
            putchar('\n');
        }

        if (!iscntrl(c)){
            putchar(c);
            width++;
        } else {
            if (c != '\n'){
                width += printf("0x%x",c);
            }

        }
    }
    return 0;
}
