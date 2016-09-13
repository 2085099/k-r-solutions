 /* Exercise 3-5
  * Write the function itob(n,s,b) that converts the integer
  * n into a base b character representation in the string s.
  * In particular, itob(n,s,16) formats s as a hexadecimal
  * integer in s.
  */

#include <stdio.h>
#include <limits.h>

#define MAX_CHARS 100

void itob(int n, char s[], int b);
void reverse(char s[]);


int main()
{
    char s[MAX_CHARS];

    itob(100, s, 16);
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

void itob(int n, char s[], int b){
    int i, sign, j;

    sign = n;
    i = 0;

    do {
        j = abs(n % b);
         /* Convert depending on base. E.g. hexadecimal) */
        s[i++] = (j < 10) ? j+'0' : j+'a'-10;

    } while ((n /= b) > 0);

    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}
