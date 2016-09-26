/* Exercise 5-11
 * Modify the programs entab and detab (written as exercises in
 * Chapter 1) to accept a list of tab stops as arguments. Use the
 * default tab settings if there are no arguments.
 */

#define TABSTOP 8 /* Width of tab */

#include <stdio.h>
#include <stdlib.h>

int next_tab_stop(int argc, char *argv[], int pos);

int main(int argc, char *argv[])
{
    int c, pos, blanks, tabs, ntabstop, index;

    pos = blanks = tabs = 0;
    index = 1;
    ntabstop = next_tab_stop(argc, argv, index++);

    while ((c = getchar()) != EOF){

           if (pos = ntabstop){
                pos = 1;
                ntabstop = next_tab_stop(argc, argv, index++);
           } else {
                pos++;
           }


           if (c == ' '){
                if (pos == ntabstop){
                    tabs++;
                    pos = 0;
                    blanks = 0;
                    ntabstop = next_tab_stop(argc, argv, index++);
                } else {
                    blanks++;
                }

           }

           else {
                if (c == '\t'){
                    pos = 0;
                    blanks = 0;
                    ntabstop = next_tab_stop(argc, argv, index++);
                }

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
                    ntabstop = next_tab_stop(argc, argv, index++);
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

int next_tab_stop(int argc, char *argv[], int index){
    static int lastvar;
    int x, temp;

    if (index == 1){
        lastvar = 0;
    }

    if (index < argc){
        x = atoi(argv[index]);
        temp = x - lastvar;

        return temp;
    } else {
        return TABSTOP;
    }
}
