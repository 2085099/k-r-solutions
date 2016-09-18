/* Exercise 5-2
 * Write getfloat, the floating-point analog
 * of getint. What type does getfloat return
 * as its function value?
 */

#include <stdio.h>

int getint(int *);
int getfloat(double *);
int getch(void);
void ungetch(int);

int main(void) {
	int c;
	double n;
	while ((c = getfloat(&n)) != EOF) {
		if (c)
			printf("%f\n", n);
		else
			printf("input error\n");
	}
	return 0;
}

#include <ctype.h>
int getfloat(double *pn) {
	int c, sign;

	while (isspace(c = getch()));

	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c);
		return 0;
	}
	sign = (c == '-') ? -1 : 1;

	if (c == '+' || c == '-') {
		c = getch();
	}

	for (*pn = 0.0; isdigit(c); c = getch())
		*pn = 10.0 * *pn + (c - '0');

    if (c == '.'){
        c = getch();
    }
    float p;

    for(p=1.0;isdigit(c);c=getch())
    {
        *pn = 10.0 * *pn + (c - '0');
        p *= 10.0;
    }
	*pn *= sign / p;

	if (c != EOF)
		ungetch(c);
	return c;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void) { /* get a (possibly pushed back) character */
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) { /* push back on input */
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}
