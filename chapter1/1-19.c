/* Exercise 1-19
 * Write a function reverse(s) that reverses
 * the character string s. Use it to write a
 * program that reverses its input a line at a time. */

#include<stdio.h>
#define MAXLINE 1000 /* Maximum input line size */

int getline(char line[],int lim);
void reverse(char line[], int lim);

int main(void)
{
    int len; /* length of line */
    char line[MAXLINE]; /* current line */


    while((len=getline(line,MAXLINE)) > 0){
        reverse(line, MAXLINE);
        printf("%s\n", line);
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

void reverse(char line[], int lim){
    int len;
    char temp[lim];

    for (len = 0; line[len] != '\0'; len++) /* Copy array into a temporary one.
                                             * At the same time, get length */
        temp[len] = line[len];

    int i;

    i = len - 1;

    for (i = 0; i < len; i++){
        line[i] = temp[len-i-1]; /* Work backwards from temp array, copying in reverse */
    }
    }



