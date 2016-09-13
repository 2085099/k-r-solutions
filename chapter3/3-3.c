/* Exercise 3-3
 * Write a function expand(s1,s2) that expands shorthand notations
 * like a-z in the string s1 into the equivalent complete list
 * abc...xyz in s2. Allow for letters of either case and digits,
 * and be prepared to handle cases like a-b-c and a-z0-9 and -a-z.
 * Arrange that a leading or trailing -is taken literally.
 */

#include<stdio.h>
#define MAX_CHARS 100

void expand(char s1[],char s2[]);

int main(void)
{
    char s1[] = "a-z";

    char s2[MAX_CHARS];

    expand(s1,s2);

    printf("%s",s2);

    return 0;
}



void expand(char s1[],char s2[])
{
    /* i is pointer for s1, j is pointer for s2 */
    int i,j,c;

    i=j=0;

    while((c=s1[i++]) != '\0')
        if(s1[i]=='-' && s1[i+1] >= c) {
            i++;
            /* Assign next character while the end is not reached */
            while(c < s1[i])
                s2[j++]=c++;
        }

        else{
            s2[j++]=c;
        }

    s2[j]='\0';
}
