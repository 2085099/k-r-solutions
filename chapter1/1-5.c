/* Exercise 1-5
*  Modify the temperature conversion program to print
*  the table in reverse order, that is, from 300 degrees to 0.
*/


#include <stdio.h>
#include <stdlib.h>

int main()
{

    float fahr, celsius;
    int upper, lower, step;

    lower = 0; /* lower bound for temperature table */
    upper = 300; /* upper bound for temperature table */
    step = 20; /* interval size for table */

    celsius = upper;
    printf("Celsius\tFahrenheit\n");
    while (celsius >= lower){
        fahr = ((9.0/5.0)*celsius) + 32;
        printf("%.1f\t%.1f\n",celsius, fahr);
        celsius -= step;
    }
    return 0;
}
