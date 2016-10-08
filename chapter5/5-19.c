/* Exercise 5-19
 * Modify undcl so that it does not add
 * redundant parentheses to declarations.
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100

enum{ NAME, PARENS, BRACKETS };

void dcl(void);
void dirdcl(void);

int gettoken(void);
int nexttoken(void);
int tokentype; /* type of last token */
int prevtoken;
char token[MAXTOKEN]; /* last token string */
char name[MAXTOKEN]; /* identifier name */
char datatype[MAXTOKEN]; /* data type = char, int, etc. */
char out[1000]; /* output string */

/* undcl: convert word description to declaration */
int main()
{
    int type;
    char temp[MAXTOKEN];

    while (gettoken() != EOF){
        strcpy(datatype, token);
        while ((type = gettoken()) != '\n')
            if (type == PARENS || type == BRACKETS)
                strcat(out, token);
            else if (type == '*'){
                if ((type = nexttoken()) == PARENS || type == BRACKETS)
                    strcat(out, token);

                sprintf(temp, "(*%s)", out);
                strcpy(out, temp);
            } else if (type == NAME){
                sprintf(temp, "%s %s", token, out);
                strcpy(out, temp);
            } else
                printf("Invalid input at %s\n", token);
        printf("%s\n", out);
    }
    return 0;
}

int gettoken(void){ /* return next token */
    int c, getch(void);
    void ungetch(int);
    char *p = token;

    if (prevtoken){
        prevtoken = 0;

        return tokentype;
    }

    while ((c = getch()) == ' ' || c == '\t');

    if (c == '('){
            if ((c = getch()) == ')'){
                strcpy(token, "()");
                return tokentype = PARENS;
            } else {
                ungetch(c);
                return tokentype = '(';
            }
        } else if (c == '['){
            for (*p++ = c; (*p++ = getch()) != ']'; );
            *p = '\0';
            return tokentype = BRACKETS;
        } else if (isalpha(c)){
            for (*p++ = c; isalnum(c = getch()); )
                *p++ = c;
            *p = '\0';
            ungetch(c);
            return tokentype = NAME;
        } else{
            return tokentype = c;}

}

int nexttoken(){
    int type;
    extern int prevtoken;

    type = gettoken();
    prevtoken = 1;
    return type;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void) { /* get a (possibly pushed back) character */
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) { /* push character back on input */
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}
