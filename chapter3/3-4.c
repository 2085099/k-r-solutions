 /* Exercise 3-4
  * In a two's complement number representation, our version
  * of itoa does not handle the largest negative number, that is, the
  * value of n equal to -(2^(wordsize-1)). Explain why not. Modify it
  * to print that value correctly, regardless of the machine on which it runs.
  */

#include <stdio.h>
#include <limits.h>

#define MAX_CHARS 100

void itoa(int n, char s[]);
void reverse(char s[]);


int main()
{
    char s[MAX_CHARS];

	itoa(INT_MAX, s);
	printf("%s\n", s);

	itoa(INT_MIN, s);
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

void itoa(int n, char s[]){
    int i, sign;

    if ((sign = n) < 0)
        n = -n;
    i = 0;

    do {
        s[i++] = abs(n % 10) + '0';

    } while ((n /= 10) != 0);

    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}
