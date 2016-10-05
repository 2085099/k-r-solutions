/* Exercise 5-13
 * Write the program tail, which prints the last n lines of its
 * input. By default, n is 10, let us say, but it can be changed
 * by an optional argument, so that
 *  tail -n
 *
 * prints the last n lines. The program should behave rationally
 * no matter how unreasonable the input or the value of n.
 * Write the program so it makes the best use of available storage;
 * lines should be stored as in the sorting program of Section 5.6,
 * not in a two-dimensional array of fixed size.
 */



#include <stdio.h>
#include <stdlib.h>

#define MAXCHARS 100

char *lineptr[MAXCHARS];

int mgetline(char s[], int lim);
int readlines(char *lineptr[],char *linestor,int maxlines);
void writelines(char *lineptr[], int nlines, int nstart);

int main(int argc, char *argv[])
{
    int i, n, lines;
    char mlines[MAXCHARS];
    n = 0;


     for (i = 1; i < argc; i++) {
		if (*argv[i] == '-') {
			n = atoi(argv[i]+1);
		}
	}

    if ((lines = readlines(lineptr, mlines, MAXCHARS)) >= 0) {
		writelines(lineptr, lines, (lines > n) ? (lines - n) : 0);

    return 0;
}
}

int readlines(char *lineptr[],char *linestor,int maxlines)
{
    int len,nlines;
    char line[MAXCHARS];
    char *p = linestor;


    nlines=0;
    p = linestor;

    while((len=mgetline(line,MAXCHARS)) > 0)
        if(linestor + MAXCHARS - p < len)
            return -1;
        else
        {
            line[len-1] = '\0';
            strcpy(p,line);
            lineptr[nlines++]=p;
            p+=len;
        }
    return nlines;
}



void writelines(char *lineptr[], int nlines, int nstart) {
	int i;
	for (i = nstart; i < nlines; ++i)
		printf("%s\n", lineptr[i]);
}

int mgetline(char s[], int lim) {
	int c, i;
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
		s[i] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}
