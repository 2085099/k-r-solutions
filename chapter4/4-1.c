/* Write the function strindex(s,t) which
 * returns the position of the rightmost
 * occurrence of t in s, or -1 if there is none. */

#include <stdio.h>
#include <stdlib.h>

int strindex(char s[], char t[]);

int main()
{
    char line[] = "foxjumpfox";
    char pattern[] = "fox";

    int found = strindex(line, pattern);

    /* It should match the a the 7th position. */

    printf("%d", found);
    return 0;
}

/* Similar to the section example but instead of breaking and returning
 * value we continue to search through the line */

int strindex(char s[], char t[]){
    int i, j, k, output;

    output = -1;

    for (i = 0; s[i] != '\0'; i++){
        for (j=i, k=0; t[k] != '\0' && s[j]==t[k]; j++, k++);
        if (k>0 && t[k] == '\0')
            output = i;
    }
    return output;
}
