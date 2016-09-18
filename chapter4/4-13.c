/* Exercise 4-13
 * Write a recursive version of the function
 * reverse(s), which reverses the string s in place.
 */

#include <stdio.h>

void reverse(char s[], int lim);
void reverse_s(char s[], int lim, int i);
int main()
{
    char s1[] = "reverse";

	reverse(s1, 7);
	printf("%s\n", s1);

	return 0;
}

void reverse(char s[], int lim) {
	reverse_s(s, lim, 0);
}

void reverse_s(char s[], int lim, int i) {
	char currentchar;
	if (i < lim) {
		reverse_s(s, lim - 1, i + 1);
		currentchar = s[i];
		s[i] = s[lim - 1];
		s[lim - 1] = currentchar;
	}
}
