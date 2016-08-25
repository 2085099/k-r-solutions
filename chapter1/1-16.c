/* Exercise 1-16
 * Revise the main routine of the longest-line program
 * so it will correctly print the length of arbitrary
 * long input lines, and as much as possible of the text.
 */

#include<stdio.h>
#define MAXLINE 1000 /* Maximum input line size */

int getline(char line[],int lim);
void copy(char to[],char from[]);


int main(void)

{
    int len,max;
    char line[MAXLINE], longest[MAXLINE];

    max =0;

    while((len=getline(line,MAXLINE)) > 0)
    {
        if(len > max)
        {
            max = len;
            copy(longest,line);
        }
    }

    int j;

    for (j = 1; longest[j] != '\0'; ++j); /* Counts length of longest character array */

    if(max>0)
        printf("\n%s\n This string has length %d", longest, j-1);

    return 0;
}


int getline(char s[],int lim)
{
    int i,c;

    for(i=0;i<lim-1 && (c=getchar())!=EOF && c !='\n';++i)
        s[i] = c;

    if(c == '\n')
    {
    s[i] = c;
    ++i;
    }

    s[i] = '\0';
    return i;
}

void copy(char to[],char from[])
{
    int i;
    i=0;

    while((to[i]=from[i]) != '\0')
    ++i;
}
