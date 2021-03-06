/* Exercise 4-10
 * An alternate organization uses getline to read
 * an entire input line; this makes getch and ungetch
 * unnecessary. Revise the calculator to use this approach.
 */

#include<stdio.h>
#include<stdlib.h>
/* fmod */
#include<math.h>

#define MAX_CHARS 1000
#define MAXOP 100
#define NUMBER '0'

int getop(char []);
void push(double);
double pop(void);
int stackcounter(void);
double topstack(void);
void duplicate(void);
void swap(void);
void clear(void);
int get_line(int line[], int limit);

/* reverse polish calculator */

int line[MAX_CHARS];
int linenumb = 0;

int main(void)
{
    int type;
    double op2;
    char s[MAXOP];


    get_line(line, MAX_CHARS);
    while((type = getop(s)) != EOF)
    {
        switch(type)
        {
                case NUMBER:
                        push(atof(s));
                        break;
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
                case '%':
                        op2 = pop();
                        if(op2 != 0.0)
                            push(fmod(pop(),op2));
                        else
                            printf("error:zero divisor\n");
                        break;
                case 't':
                        printf("%g\n", topstack());
                        break;
                case 'd':
                        duplicate();
                        break;
                case 's':
                        swap();
                        break;

                case 'c':
                        clear();

                /* Sin */
                case 'q':
                        push(sin(pop()));
                        break;
                /* Cos */
                case 'w':
                        push(cos(pop()));
                        break;
                /* Tan */
                case 'e':
                        push(tan(pop()));
                        break;
                /* Exp */
                        push(exp(pop()));
                        break;
                /* Pow */
                case 'r':
                        op2 = pop();
                        push(pow(pop(), op2));
                        break;

                case '\n':
                        printf("\t%.8g\n", topstack());
                        get_line(line, MAX_CHARS);
                        linenumb = 0;
                        break;
                default:
                        printf("error: unknown command %s\n",s);
                        break;

        }
    }
    return 0;
}


#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

int stackcounter() {
	return sp;
}

double topstack(){
    if (stackcounter() > 0)
        return val[sp-1];
    else {
        printf("Stack empty");
        return 0.0;
    }
}

void duplicate(){
    if (stackcounter() > 0){
        push(topstack());
    } else{
        printf("Stack empty");
    }
}

void swap(){
    if (stackcounter() > 1){
        double first;
        double second;

        first = pop();
        second = pop();

        push(first);
        push(second);

    } else {
        printf("Need more elements");
    }
}

void clear(){
    sp = 0;
}
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

int getop(char s[])
{
    int i,c;

    while((s[0] = c = line[linenumb++]) == ' ' || c =='\t')
        ;
    s[1] = '\0';

    i = 0;
    if(!isdigit(c) && c!='.' && c!='-')
        return c;

    if(c=='-')
        if(isdigit(c=line[linenumb++]) || c == '.')
            s[++i]=c;
        else
        {
            if(c!=EOF)
                ungetch(c);
            return '-';
        }

    if(isdigit(c))
        while(isdigit(s[++i] =c =line[linenumb++]))
            ;

    if(c=='.')
        while(isdigit(s[++i] = c=line[linenumb++]))
            ;
    linenumb--;
    s[i] = '\0';
    if(c!=EOF)
        ungetch(c);
    return NUMBER;
}

int get_line(int s[], int limit){
    int c, i;

	for (i=0; i < limit-1 && (c=getchar()) != EOF && c!= '\n'; ++i)
		s[i] = c;

	s[i++] = c;

	s[i] = '\0';

	return i;
}
