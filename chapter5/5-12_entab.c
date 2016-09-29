/* Exercise 5-12
 * Extend entab and detab to accept the shorthand
 * entab -m +n
 * to mean tab stops every n columns, starting at column m. Choose convenient
 * (for the user) default behavior.
 */

#define TABSTOP 8 /* Width of tab */

#include <stdio.h>
#include <stdlib.h>

int next_tab_stop(int argc, char *argv[], int pos);

int main(int argc, char *argv[])
{
    int i, c, pos, post, blanks, tabs, ntabstop, index, m, n;

    pos = blanks = tabs = 0;

    for (i = 1; i < argc; i++) {
		if (argv[i][0] == '-' && isdigit(argv[i][1])) {
			m = atoi(argv[i]+1);
		}
		else if (argv[i][0] == '+' && isdigit(argv[i][1])) {
			n = atoi(argv[i]+1);
		}
	}

    ntabstop = next_tab_stop(m, n, post);

    while ((c = getchar()) != EOF){

           if (pos = ntabstop){
                pos = 1;
                ntabstop = next_tab_stop(m, n, post);
           } else {
                pos++;
           }


           if (c == ' '){
                if (pos == ntabstop){
                    tabs++;
                    pos = 0;
                    blanks = 0;
                    ntabstop = next_tab_stop(m, n, post);
                } else {
                    blanks++;
                }

           }

           else {
                if (c == '\t'){
                    pos = 0;
                    blanks = 0;
                    ntabstop = next_tab_stop(m, n, post);
                }

                /* flush blanks */

                while (tabs > 0){
                    tabs--;
                    putchar('\t');
                }

                while (blanks > 0){
                    blanks--;
                    putchar(' ');
                }

                putchar(c);

                if (c == '\n') {
                    pos = tabs = blanks = 0;
                    index = 1;
                    ntabstop = next_tab_stop(m, n, post);
			}
           }

    }
    while (tabs > 0){
        tabs--;
        putchar('\t');
    }

    while (blanks > 0){
        blanks--;
        putchar(' ');
    }


    return 0;
}

int next_tab_stop(int m, int n, int post){
    return (post >= m) ? n : TABSTOP;
}
