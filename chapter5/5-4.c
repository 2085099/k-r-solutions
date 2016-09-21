/* Exercise 5-4
 * Write the function strend(s,t), which returns
 * 1 if the string t occurs at the end of the
 * string s, and zero otherwise.
 */

#include <stdio.h>
#include <stdlib.h>

int mstrend(char *s, char *t);

int main()
{
    char a[] = "abc";
	char b[] = "def";
	printf("%d\n", mstrend("abcdef", "def"));

    return 0;
}

int mstrend(char *s, char *t){

	for (; *s; s++)
		t = (*s == *t) ? t + 1 : t;

	return *t++ == '\0';

}
