/* Exercise 1-18
 * Write a Program to remove the trailing blanks and tabs from each input line
 * and to delete entirely blank lines
*/

#include<stdio.h>
#define MAXLINE 1000 /* Maximum input line size */

int getline(char line[],int lim);
int removeblanks(char line[], int end);

int main(void)
{
    int len; /* length of line */
    char line[MAXLINE]; /* current line */


    while((len=getline(line,MAXLINE)) > 0)
        if(removeblanks(line, len) > 0){ /* If line is not blank */

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

/* Begin at the end of the string and work backwards
 * to remove trailing blanks */

int removeblanks(char s[], int end){

        int i;

        for ( i = end - 2; i >= 0; --i){ /* We need the raw string, so we remove \0 and \n from the end */
            if ((s[i] == ' ') || (s[i] == '\t')){
                end = i;
            }
            else{
                break;
            }
        }

        if (end > 0){
            s[end] = '\n';
            s[end+1] = '\0';
        }


        return i;
    }


