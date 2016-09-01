/* Exercise 2-3
 * Write a function htoi(s), which converts a string of
 * hexadecimal digits (including an optional 0x or 0X)
 * into its equivalent integer value. The allowable digits
 * are 0 through 9, a through f,and A through F.
 */

#include <stdio.h>
#include <stdlib.h>

int htoi(char hex[]);

int main()
{
    printf("%d", htoi("A33FF"));
    return 0;
}

int htoi(char hex[]){
    int i, n;

    i = n = 0;

    if (hex[0] == '0' && (hex[1] == 'x' || hex[1] == 'X')){
        i = 2; /* if hex code begins with 0x or 0X, go straight to the part to be converted */

    }

    while (hex[i] != '\0'){
            n *= 16;
        if (hex[i] >= '0' && hex[i] <= '9'){
            n += hex[i] - '0';
        }

        if (hex[i] >= 'a' && hex[i] <= 'f'){
            n += 10 + hex[i] - 'a';
        }

        if (hex[i] >= 'A' && hex[i] <= 'F'){
            n += 10 + hex[i] - 'A';
        }
    i++;
    }
    return n;
    }
