 /* Exercise 3-6
  * Write a version of itoa that accepts three arguments
  * instead of two. The third argument is a minimum field
  * width; the converted number must be padded with blanks on
  * the left if necessary to make it wide enough.
  */

#include <stdio.h>
#include <limits.h>

#define MAX_CHARS 100

void itoa(int n, char s[], int w);
void reverse(char s[]);


int main()
{
    char s[MAX_CHARS];

	itoa(INT_MAX, s, 15);
	printf("%s\n", s);

	itoa(INT_MIN, s, 20);
	printf("%s\n", s);

    return 0;
}

void reverse(char s[]) {
  int c, i, j;
  for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}

void itoa(int n, char s[], int w){
    int i, sign;

    sign = n;
    i = 0;

    do {
        s[i++] = abs(n % 10) + '0';

    } while ((n /= 10) != 0);

    if (sign < 0)
        s[i++] = '-';

    while (i < w)
        s[i++] = ' ';
    s[i] = '\0';
    reverse(s);
}
