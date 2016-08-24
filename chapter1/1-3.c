/* Exercise 1-3
*  Modify the temparture conversion program to print
*  a heading above the table
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

    fahr = lower; /* Starting point for fahrenehit */
    printf("Fahrenheit\tCelsius\n"); /* Headers as required */
    while (fahr<= upper){
        celsius = ((5.0/9.0)*(fahr - 32.0)); /* Temperature conversion */
        printf("%f\t%f\n",fahr, celsius);
        fahr += step;
    }
    return 0;
}
