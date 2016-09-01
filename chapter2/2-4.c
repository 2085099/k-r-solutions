/* Exercise 2-4
 * Write an alternate version of squeeze(s1,s2) that deletes
 * each character in s1 that matches any character in the string s2.
 */

#include <stdio.h>
#include <stdlib.h>

void squeeze(char s1[], char s2[]);

int main()
{
    char s1[] = "KRExercise2-4";
    char s2[] = "i2";

    squeeze(s1,s2);

    printf("%s", s1);
    return 0;
}

void squeeze(char s1[], char s2[]){
 int i, j, k; /* i points through s1, j points through s2
               * and k keeps a record of where we are in s1
               */

 k=0;

 /* Iterate through s1 */
 for (i = 0; s1[i] != '\0'; ++i){
        /* Iterate through s2 for a single char in s1. If they match,
         * we can skip the iteration. Since the for loop is skipped,
         * s2[j] will not be equal to '\0' (j would not have reached s2 size.
         * We can now avoid this specific char.
         */

        for (j = 0; (s1[i] != s2[j]) && s2[j] != '\0'; ++j);

        /* This will be valid if the chars in s1 and s2 did not match
         * since s2[j] will be equal to '\0'. We can then update our
         * char array
         */
        if (s2[j] == '\0'){
            s1[k] = s1[i];
            ++k;
        }
 }
    s1[k] = '\0';
}
