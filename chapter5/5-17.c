/* Exercise 5-17
 * Add a field-handling capability, so sorting may be done on fields
 * within lines, each field sorted according to an independent set of options. (The
 * index for this book was sorted with -df for the index category and -n for the
 * page numbers')
 */

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAXCHARS 100

int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int nlines);
void swap(void *v[], int i, int j);
void mqsort(void *v[], int left, int right, int (*comp)(void *, void *));

int mstrcmp(char *s1, char *s2);
int numcmp(char *s1, char *s2);


char *lineptr[MAXCHARS];

    int reverse = 1;
    int fold = false;
    int direc = false;
    int start = 0;
    int end = 0;

int main(int argc, char *argv[])
{
    int i, nlines, numeric;

    numeric = false;


    for (i = 1; i < argc; i++){
        if (strcmp(argv[i], "-n") == 0){
            numeric = true;
        }
        else if (strcmp(argv[i], "-r") ==0){
            reverse = true;
        }
        else if(strcmp(argv[i], "-f") == 0){
            fold = true;
        }
        else if(strcmp(argv[i], "-d") == 0){
            direc = true;
        }
        else if(strcmp(argv[i], "+") && (start = atoi(++argv[i])) < 0){
            start = -1;
        }
        else if(strcmp(argv[i], "-") && (start = atoi(++argv[i])) < 0){
            end = -1;
        }
    }

    if ((nlines = readlines(lineptr, MAXCHARS)) >= 0){
        mqsort((void **) lineptr, 0, nlines - 1, (int (*)(void *, void *))(numeric ? numcmp : mstrcmp));
        writelines(lineptr, nlines);
    }
    return 0;
}

void mqsort(void *v[], int left, int right, int (*comp)(void *, void *)) {
	int i, last;
	void swap(void *v[], int, int);

	if (left >= right)
		return;
	swap(v, left, (left + right) / 2);
	last = left;
	for (i = left + 1; i <= right; i++)
		if (reverse * (*comp)(v[i], v[left]) < 0)
			swap(v, ++last, i);
	swap(v, left, last);
	mqsort(v, left, last-1, comp);
	mqsort(v, left+1, right, comp);
}

#include <stdlib.h>

int numcmp(char *s1, char *s2) {
	double v1, v2;

	v1 = atof(s1);
	v2 = atof(s2);

	if (v1 < v2)
		return -1;
	else if (v1 > v2)
		return 1;
	else
		return 0;
}

int mstrcmp(char *s1, char *s2){
    int i;
    s1 += start;
    s2 += start;

    if (direc){
        for(; !isdigit(*s1) && !isalpha(*s1) && !isspace(*s1) && *s1; *s1++);
        for(; !isdigit(*s2) && !isalpha(*s2) && !isspace(*s2) && *s2; *s2++);
    }

    for (i = 0; i < (end-start); fold ? (tolower(*s1) == tolower(*s2)) : (*s1 == *s2)){
        if (*s1 == '\0')
            return 0;

        s1++;
        s2++;

        if (direc){
            for(; !isdigit(*s1) && !isalpha(*s1) && !isspace(*s1) && *s1; *s1++);
            for(; !isdigit(*s2) && !isalpha(*s2) && !isspace(*s2) && *s2; *s2++);
        }
    }

    return (fold ? (tolower(*s1) - tolower(*s2)) : (*s1 - *s2));

}



char *alloc(int);

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines)
{
	int len, nlines;
	char *p, line[MAXCHARS];

	nlines = 0;
	while ((len = mgetline(line, MAXCHARS)) > 0)
		if (nlines >= maxlines || (p = alloc(len)) == NULL)
			return -1;
		else {
			line[len - 1] = '\0';
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
	int i;

	for (i = 0; i < nlines; i++)
		printf ("%s\n", lineptr[i]);
}

void swap(void *v[], int i, int j) {
	void *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

int mgetline(char s[], int limits)
{
    int i;
    for (i = 0; i < limits - 1 && (s[i] = getchar()) != EOF && s[i] != '\n'; i++);
    if (s[i] == '\n')
		i++;
    s[i] = '\0';
    return i;
}

#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n)
{
    if (allocbuf + ALLOCSIZE - allocp >= n) {
		allocp += n;
		return allocp - n;
    } else
		return 0;
}
