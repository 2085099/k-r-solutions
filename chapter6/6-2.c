/* Exercise 6-2
 * Write a program that reads a C program and prints in alphabetical
 * order each group of variable names that are identical in the first 6 characters,
 * but different somewhere thereafter. Don't count words within strings and
 * comments. Make 6 a parameter that can be set from the command line.
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100
#define FIRST_N 6;

int getchnew(void);
struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);

struct tnode{
    char *word;
    struct tnode *left;
    struct tnode *right;
};

int main(int argc, char *argv[])
{
    struct tnode *root;

    char word[MAXWORD];
    int n = FIRST_N;
    
	/* Unsigned char to ensure n will be positive */
	if (argc == 2 && isdigit((unsigned char) argv[1][0])) {
		n = atoi(argv[1]);
	}
	
	root = NULL;
	
	while (getword(word, MAXWORD) != EOF)
		if ((isalpha((unsigned char)word[0])) && (unsigned char)strlen(word) >= n){
			root = addtree(root, word);
		} 
		
	treeprint(root);
    return 0;
}

struct tnode *talloc(void);
char *str(char *);

/* addtree: add a node with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w)
{
	int cond;
	
	if (p == NULL){
		p = talloc();
		p->word = strdup(w);
		p->left = p->right = NULL;
	} else if((cond = strcmp(w, p->word))<0)
		p->left = addtree(p->left, w);
	else if (cond > 0)		
		p->right = addtree(p->right, w);
	
	return p;
}

void treeprint(struct tnode *p)
{
	if (p != NULL){
		treeprint(p->left);
		printf(" %s\n", p->word);
		treeprint(p->right);
	}
}

struct tnode *talloc(void) {
	return (struct tnode *) malloc(sizeof(struct tnode));
}

/* getword: get next word or character from input */
int getword(char *word, int lim)
{
    int c, getch(void);
    void ungetch(int);
    char *w = word;

    while (isspace(c = getchnew()));

    if (c != EOF)
        *w++ = c;
    if (!isalpha(c) && c != '_'){
        *w = '\0';
        return c;
    }
    for (; --lim > 0; w++)
        if (!isalnum(*w = getchnew()) && *w != '_'){
            ungetch(*w);
            break;
        }
    *w = '\0';
    return word[0];
}

int getch(void);
void ungetch(int);
#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

int getchnew(void){
    int c;
    static int prevc = 0;

    c = getch();

    if (c == EOF)
        return EOF;

    // Preprocessor
    if (c == '#'){
        while ((c = getch()) != '\n')
            if (c == EOF) return EOF;
    }

    // Comment
    if (prevc == '/' && c == '*'){
        while ((c = getch())){
            if (c == EOF) return EOF;
            if (prevc == '*' && c == '/') break;
            prevc = c;
        }

    }

    // String constant
    if (c == '"'){
        while ((c = getch())){
            if (c == EOF) return EOF;
            if (c == '"') break;
            prevc = c;
        }
    }

    prevc = c;

    return c;

}

void ungetch(int c)
{
    if(bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

