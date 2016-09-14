#include <stdio.h>

double atof(char s[]);

int main()
{
    double atof(char []);

    printf("%f\n", atof("111.111"));
    printf("%f\n", atof("1e2")); // 123450000.000000
	printf("%f\n", atof("11e-2")); // 0.000123
    return 0;
}

double atof(char s[]){
    double val, power;
    int i, sign;

    /* Skip white space */
    for(i = 0; isspace(s[i]); i++);

    /* Determine positive or negative */
    sign = (s[i] == '-') ? -1 : 1;

    if (s[i] == '+' || s[i] == '-')
        i++;

    for(val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;

    for(power = 1.0; isdigit(s[i]); i++){
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }

    /* Set up for e values */

    double emultiply;
    int e, esign;
    if (s[i] == 'e' || s[i] == 'E')
        i++;


    esign = (s[i] == '-') ? -1 : 1;

    if (s[i] == '+' || s[i] == '-')
        i++;


    for (e = 0; isdigit(s[i]); i++)
        e = 10 * e + (s[i] - '0');

    for (emultiply = 1.0; e > 0; e--)
        emultiply *= 10;

    if (esign == -1 && emultiply != 0)
        emultiply = 1 / emultiply;

    return sign * val * emultiply / power;

}
