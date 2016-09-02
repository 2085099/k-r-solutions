/* Exercise 2-5
 * Write the function any(s1,s2), which returns the first location
 * in the string s1 where any character from the string s2 occurs, or -1 if s 1
 * contains no characters from s2. (The standard library function strpbrk does
 * the same job but returns a pointer to the location.)
 */

#include <stdio.h>
#include <stdlib.h>

int any(char s1[], char s2[]);

int main()
{
    char s1[] = "KRExercise2-5";
    char s2[] = "i2";

    any(s1,s2);

    printf("%d", any(s1,s2));
    return 0;
}

int any(char s1[], char s2[]){
 int i, j;

 for (i = 0; s1[i] != '\0'; ++i){

     /* Looking through each char in s2, whenever s1[i] and
      *  s2[j] match we can return the position of the match.
      */
        for (j = 0; (s1[i] == s2[j]) && s2[j] != '\0'; ++j)
            return i;

 }
    return -1;
}
