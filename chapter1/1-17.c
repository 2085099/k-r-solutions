/* Exercise 1-17
 * Write a program to print all input lines
 * that are longer than 80 characters.
 */

#include<stdio.h>
#define MAXLINE 1000 /* Maximum input line size */
#define MINIMUM 81 /* Minimum input line size (80+) in order to print */

int getline(char line[],int lim);

int main(void)
{
    int len; /* length of line */
    char line[MAXLINE]; /* current line */


    while((len=getline(line,MAXLINE)) > 0)
        if(len > MINIMUM){ /* If line has larger length than minimum*/

             printf("%s", line);
        }

    return 0;
}


int getline(char s[],int lim)
{
    int c, i;
    for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i) /* grab line */
        s[i] = c;

    if (c == '\n'){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';

    return i; /* returns length */
}



