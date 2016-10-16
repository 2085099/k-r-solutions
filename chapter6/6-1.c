/* Exercise 6-1
 * Our version of getword does not properly handle underscores,
 * string constants, comments, or preprocessor control lines.
 * Write a better version.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXWORD 100
#define NKEYS (sizeof keytab / sizeof(struct key))

struct key {
	char *word;
	int count;
} keytab[] = {
	"auto", 0,
	"break", 0,
	"case", 0,
	"char", 0,
	"const", 0,
	"continue", 0,
	"default", 0,
	"define", 0,
	"unsigned", 0,
	"void", 0,
	"while", 0,
};
int getchnew(void);
int getword(char *, int);
int binsearch(char *, struct key *, int);

/* count C keywords */
int main()
{
    int n;
    char word[MAXWORD];

    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            if ((n = binsearch(word, keytab, NKEYS)) >= 0)
                keytab[n].count++;
    for (n = 0; n < NKEYS; n++)
        if (keytab[n].count > 0)
            printf("%4d %s\n", keytab[n].count, keytab[n].word);
    return 0;
}

/* binsearch: find word in tab[0]...tab[n-1] */
int binsearch(char *word, struct key tab[], int n)
{
    int cond;
    int low, high, mid;

    low = 0;
    high = n-1;

    while(low <= high){
        mid = (low+high) / 2;
        if((cond = strcmp(word, tab[mid].word)) < 0)
            high = mid - 1;
        else if (cond > 0)
            low = mid + 1;
        else
            return mid;
    }

    return -1;
}

/* getword: get next word or character from input */
int getword(char *word, int lim)
{
    int c, getch(void);
    void ungetch(int);
    char *w = word;

    while (isspace(c = getchnew()));

    if (c != EOF)
        *w++ = c;
    if (!isalpha(c) && c != '_'){
        *w = '\0';
        return c;
    }
    for (; --lim > 0; w++)
        if (!isalnum(*w = getchnew()) && *w != '_'){
            ungetch(*w);
            break;
        }
    *w = '\0';
    return word[0];
}

int getch(void);
void ungetch(int);
#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

int getchnew(void){
    int c;
    static int prevc = 0;

    c = getch();

    if (c == EOF)
        return EOF;

    // Preprocessor
    if (c == '#'){
        while ((c = getch()) != '\n')
            if (c == EOF) return EOF;
    }

    // Comment
    if (prevc == '/' && c == '*'){
        while ((c = getch())){
            if (c == EOF) return EOF;
            if (prevc == '*' && c == '/') break;
            prevc = c;
        }

    }

    // String constant
    if (c == '"'){
        while ((c = getch())){
            if (c == EOF) return EOF;
            if (c == '"') break;
            prevc = c;
        }
    }

    prevc = c;

    return c;

}

void ungetch(int c)
{
    if(bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
