/* Exercise 1-12
* Write a program that prints its input one word per line.
*/

#include <stdio.h>
#include <stdlib.h>


int main()
{
    int c;

    while ((c = getchar()) != EOF){

           if (c == ' '){ /* As soon as a blank char is reached, create new line */
                putchar('\n');
           }

           else {
                putchar(c);
           }

    }

    return 0;
}
