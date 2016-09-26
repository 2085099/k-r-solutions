/* Exercise 5-11
 * Modify the programs entab and detab (written as exercises in
 * Chapter 1) to accept a list of tab stops as arguments. Use the
 * default tab settings if there are no arguments.
 */

#define TABSTOP 8 /* Width of tab */

#include <stdio.h>
#include <stdlib.h>

int next_tab_stop(int argc, char *argv[], int index);

int main(int argc, char *argv[])
{
    int c, pos;
    int index = 1;
    pos = 1;

    int ntabstop = next_tab_stop(argc, argv, index);

    while ((c = getchar()) != EOF){

            /* NOTE: tabs are replaced with '-' */
            if (c == '\t'){
               while (pos < ntabstop){
                    putchar(' ');
                    pos++;
               }

                pos = 0;
                ntabstop = next_tab_stop(argc, argv, index);

            }

            else {
                putchar(c);

                if (c == '\n'){
                    index = 1;
                    pos = 0;
                    ntabstop = next_tab_stop(argc, argv, index);
                }

                else if (++pos == ntabstop){
                    pos = 0;
                    ntabstop = next_tab_stop(argc, argv, index);

                }

            }

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

