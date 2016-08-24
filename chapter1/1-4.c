/* Exercise 1-4
*  Write a program to print the corresponding
*  Celsius to Fahrenheit table
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{

    float fahr, celsius;
    int upper, lower, step;

    lower = 0; /* lower bound for temperature table */
    upper = 100; /* upper bound for temperature table */
    step = 10; /* interval size for table */

    celsius = lower;
    printf("Celsius\tFahrenheit\n");
    while (celsius <= upper){
        fahr = ((9.0/5.0)*celsius) + 32;
        printf("%.1f\t%.1f\n",celsius, fahr);
        celsius += step;
    }
    return 0;
}
