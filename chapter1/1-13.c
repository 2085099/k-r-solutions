/* Exercise 1-13
* Write a program to print a histogram of the lengths of words in its input.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int c;

    while ((c = getchar()) != EOF){

        if (c == ' ' || c == '\t' || c == '\n'){
            putchar('\n');
            }

        else {
            putchar('*');
        }
    }

    return 0;

}

