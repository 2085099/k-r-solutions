/* Exercise 4-12
 * Adapt the ideas of printd to write a recursive
 * version of itoa; that is, convert an integer
 * into a string by calling a recursive routine.
 */

#include <stdio.h>
#define MAX 100

void itoa(int n, char s[]);
int main()
{
    char s1[MAX];

	itoa(200, s1);
	printf("%s\n", s1);


    return 0;
}

void itoa(int n, char s[]){
    static int i;
    if (n < 0){
        s[i++] = '-';
    }

    if (n / 10){
        itoa(n/10, s);
    } else {
    i = 0;
    }

    s[i++] = abs(n) % 10 + '0';
    s[i] = '\0';
}
