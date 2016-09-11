/* Exercise 3-2
 * Write a function escape(s,t) that converts characters
 * like newline and tab into visible escape sequences like
 * n and t as it copies the string t to s. Use a switch.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_CHARS 1000
void escape(char s[], char t[]);

int main()
{
    char s1[] = "Escape\nRandom\nTest\tPass";
    char t1[MAX_CHARS];


	escape(t1, s1);

	printf("%s\n", t1);


    return 0;
}

void escape(char s[], char t[]){

    int i, j;
    i = j = 0;

    for(i = 0; t[i] != '\0'; i++){
        switch(t[i]){
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                break;
            default:
                s[j++] = t[i];
                break;
        }
    }
    s[j] = '\0';
}


