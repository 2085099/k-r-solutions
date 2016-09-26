/* Exercise 5-10
 * Write the program expr, which evaluates a
 * reverse Polish expression from the command line,
 * where each operator or operand is a separate argument.
 * For example,

 * expr 2 3 4 + *
 * evaluates 2 x (3+4).
 */

#include<stdio.h>
#include<stdlib.h>
/* fmod */
#include<math.h>

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

/* reverse polish calculator */

int main(int argc, char *argv[])
{
    int type, i;
    double op2;
    char s[MAXOP];

    while(i < argc)

        type = getop(argv[i]);
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


int getop(char s[])
{
    int c = s[0];

    if(isdigit(c) || (c == '.' && isdigit(s[1])) || (c == '-' && (isdigit(c))) || (s[1] == '.' && isdigit((unsigned char) s[2]))){
       return NUMBER;
    }


    return c;
}

