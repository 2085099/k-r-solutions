/* Exercise 1-15
* Rewrite the temperature conversion program
* of Section 1.2 to use a function for conversion.
*/

#include <stdio.h>
#include <stdlib.h>


void fahrtocelsius(void);
void celsiustofahr(void);

int main()
{

    void fahrtocelsius(){
        float fahr;
        for (fahr = 0; fahr <= 300; fahr += 20)
            printf("%.1f\t%.1f\n", fahr, (5.0/9.0)*(fahr-32));
        }

    void celsiustofahr(){
        float celsius;

        for (celsius = 0; celsius <= 100; celsius += 10)
            printf("%.1f\t%.1f\n", celsius, ((9.0/5.0)*celsius) + 32);
        }

        fahrtocelsius();


    return 0;
}
