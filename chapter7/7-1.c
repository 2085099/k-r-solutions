/* Exercise 7-1
 * Write a program that converts upper case
 * to lower or lower case to upper, depending on the
 * name it is invoked with, as found in argv[0]
 */

#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]) /* lower: convert input to lower case */
{
    int c;

    /* E.g. "./7-1 upper" would satisfy condition if argv[1] */

    while ((c = getchar()) != EOF)
        putchar((strcmp(argv[0], "upper") == 0) ? toupper(c) : tolower(c));
    return 0;
}
