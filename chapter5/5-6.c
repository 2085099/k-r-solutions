/* Exercise 5-6
 * Rewrite appropriate programs from
 * earlier chapters and exercises with pointers
 * instead of array indexing.
 */

#include <stdio.h>
#include <string.h>

#define MAX_CHARS 100

int mgetline(char *s, int lim);

int main()
{
    char line[MAX_CHARS];

    while(mgetline(line, MAX_CHARS) != EOF)
        printf("%s", line);
    return 0;
}

int mgetline(char *s, int lim){
    int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
		*s++ = c;

    *s++ = '\n';
	*s = '\0';
	return c;
}

