/* Exercise 5-5
 * Write versions of the library functions strncpy, strncat, and
 * strncmp; which operate on at most the first n characters of their argument
 * strings. For example, strncpy(s,t,n) copies at most n characters of t to s.
 * Full descriptions are in Appendix B.
 */

#include <stdio.h>


void mstrncpy(char *s, char *t, int n);
void mstrncat(char *s, char *t, int n);
int mstrncmp(char *s, char *t, int n);

int main()
{
    char a[10];
	char b[] = "abcdef";
    char c[] = "123456";

	mstrncpy(a, b,4);
	printf("%s\n", a);

	mstrncat(b,c,4);
	printf("%s\n", b);

	printf("%d\n", mstrncmp("abcdef", "abc", 3));

    return 0;
}

void mstrncpy(char *s, char *t, int n){
    int i;
	for (i = 0; i < n && (*s++ = *t++); i++);

    while (i++ < n || *s)
        *s++ = '\0';
}

void mstrncat(char *s, char *t, int n){
    int i;

    while (*s) s++;

    for (i = 0; i < n && (*s++ = *t++); i++);

    *s++ = '\0';
}

int mstrncmp(char *s, char *t, int n){
    int i;

	for (i = 0;(*s == *t) && i < n; i++, s++, t++)
		if (*s == '\0' || i == n - 1)
			return 0;

	return (*s == *t) ? 0 : *s - *t;

}
