#include <stdio.h>
#include <stdlib.h>

float power (unsigned int exponent, float basis)
{
    float potenz = 1.0;
    for (;exponent>0;exponent--)
    {
        potenz *= basis;
    }
    return potenz;
}

int main()
{
    // lokale Variablen
    float basis, potenz;
    unsigned int exponent;

    printf("Berechnung der Potenz einer reellen Basis mit\n"
           "einem ganzzahligen, nichtnegativen Exponenten\n\n");

    printf("Bitte reelle Basis eingeben: ");
    scanf("%f",&basis);
    printf("Bitte ganzzahligen, nichtnegativen Exponenten eingeben: ");
    scanf("%u",&exponent);

    printf("\nDie Potenz betraegt: %.2f",power(exponent,basis));
}
