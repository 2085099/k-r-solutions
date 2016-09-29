/* Exercise 5-12
 * Extend entab and detab to accept the shorthand
 * entab -m +n
 * to mean tab stops every n columns, starting at column m. Choose convenient
 * (for the user) default behavior.
 */

#define TABSTOP 8 /* Width of tab */

#include <stdio.h>
#include <stdlib.h>

int next_tab_stop(int m, int n, int post);

int main(int argc, char *argv[])
{
    int i, c, pos, post, m, n;
    pos = 1;

    for (i = 1; i < argc; i++) {
		if (argv[i][0] == '-' && isdigit(argv[i][1])) {
			m = atoi(argv[i]+1);
		}
		else if (argv[i][0] == '+' && isdigit(argv[i][1])) {
			n = atoi(argv[i]+1);
		}
	}

    int ntabstop = next_tab_stop(m, n, post);

    while ((c = getchar()) != EOF){
            post++;
            /* NOTE: tabs are replaced with '-' */
            if (c == '\t'){
               while (pos < ntabstop){
                    putchar('-');
                    pos++;
               }

                pos = 0;
                ntabstop = next_tab_stop(m, n, post);

            }

            else {
                putchar(c);

                if (c == '\n'){
                    post = 0;
                    pos = 0;
                    ntabstop = next_tab_stop(m, n, post);
                }

                else if (++pos == ntabstop){
                    pos = 0;
                    ntabstop = next_tab_stop(m, n, post);

                }

            }

    }
    return 0;
}

int next_tab_stop(int m, int n, int post){
    return (post >= m) ? n : TABSTOP;
}

