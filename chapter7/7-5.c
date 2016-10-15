/* Exercise 7-5
 * Rewrite the postfix calculator of Chapter 4
 * to use scanf and/or sscanf to do the input
 * and number conversion.
 */

#include<stdio.h>
#include<stdlib.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char []);
void push(double);
double pop(void);

/* reverse polish calculator */

int main(void)
{
    double op2, num;
    char s[MAXOP], b, t[MAXOP];
    char *c;

    while(scanf("%s%c", s, &b) == 2)
    {
        if (sscanf(s, "%lf", &num) == 1){
            push(num);
        }

        else if (sscanf(s, "%s", t) == 1) {
            for (c = t; *c; c++) {
                switch(*c){
                    case '+':
                        push(pop()+pop());
                        break;
                    case '*':
                        push(pop()*pop());
                        break;
                    case '-':
                        op2 = pop();
                        push(pop()-op2);
                        break;
                    case '/':
                        op2 = pop();
                        if(op2 != 0.0)
                            push(pop()/op2);
                        else
                            printf("error:zero divisor\n");
                        break;


                    default:
                        printf("error: unknown command %s\n",s);
                        break;

        }
        }

        if (b == '\n')
            printf("\t%.8g\n", pop());
    }
    }
    return 0;
}


#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f)
{
    if(sp < MAXVAL)
        val[sp++]=f;
    else
        printf("error:stack full, cant push %g\n",f);
}


double pop(void)
{
    if(sp>0)
        return val[--sp];
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}

#include<ctype.h>

int getch(void);
void ungetch(int);

int getop(char s[])
{
    int i,c;

    while((s[0] = c = getch()) == ' ' || c =='\t')
        ;
    s[1] = '\0';

    i = 0;
    if(!isdigit(c) && c!='.' && c!='-')
        return c;

    if(c=='-')
        if(isdigit(c=getch()) || c == '.')
            s[++i]=c;
        else
        {
            if(c!=EOF)
                ungetch(c);
            return '-';
        }

    if(isdigit(c))
        while(isdigit(s[++i] =c =getch()))
            ;

    if(c=='.')
        while(isdigit(s[++i] = c=getch()))
            ;

    s[i] = '\0';
    if(c!=EOF)
        ungetch(c);
    return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if(bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
