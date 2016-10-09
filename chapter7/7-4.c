/* Exercise 7-4
 * Write a private version of scanf analogous
 * to minprintf from the previous section.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
void scanscanf(char *fmt, ...);
int main()
{
    char *a= "Hello world!";
    minscanf("%s", a);

    return 0;
}


void minscanf(char *fmt, ...)
{
    va_list ap; /* points to each unnamed arg in turn */
    char *p, *sval;
    double dval, uval;
    int ival;
    void *pval;


    va_start(ap, fmt); /* make ap point to 1st unnamed arg */
    for (p = fmt; *p; p++){
        if (*p != '%'){
            putchar(*p);
            continue;
        }

        switch(*++p){
        case 'd':
            ival = va_arg(ap, int);
            scanf("%d", ival);
            break;


        case 'f':
            dval = va_arg(ap, double);
            scanf("%f", dval);
            break;

        case 's':
            for (sval = va_arg(ap, char *); *sval; sval++)
                putchar(*sval);
            break;

        case 'u':
            uval = va_arg(ap, unsigned int);
            scanf("%u", uval);
            break;

        case 'e':
            dval = va_arg(ap, double);
            scanf("%e", dval);
            break;

        case 'p':
            pval = va_arg(ap, void *);
            scanf("%p", pval);
            break;

        default:
            break;
        }
    }

    va_end(ap); /* clean up when done, must be called at the end */
}
