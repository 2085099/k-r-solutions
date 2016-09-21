/* Exercise 5-3
 * Write a pointer version of the function
 * strcat that we showed in Chapter 2: strcat(s ,t)
 * copies the string t to the end of s.
 */

#include <stdio.h>
#include <stdlib.h>

void mstrcat(char *s, char *t);

int main()
{
    char a[] = "abc";
	char b[] = "def";
	mstrcat(a, b);

	printf("%s\n", a);

    return 0;
}

void mstrcat(char *s, char *t){

    while (*s++);

    s--; /* return to \0 */
    while(*s++=*t++);

}
