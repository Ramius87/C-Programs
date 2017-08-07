#include <stdio.h>
#include <stdlib.h>

// globale Variablen
float basis,ergebnis;
unsigned int exponent;

void power(void)
{
    ergebnis = 1;
    for (;exponent>0;exponent--)
    {
        ergebnis *= basis;
    }
}

int main()
{
    printf("Berechnung der Potenz einer reellen Basis mit\n"
           "einem ganzzahligen, nichtnegativen Exponenten\n\n");

    printf("Bitte reelle Basis eingeben: ");
    scanf("%f",&basis);
    printf("Bitte ganzzahligen, nichtnegativen Exponenten eingeben: ");
    scanf("%u",&exponent);

    power();

    printf("\nDie Potenz betraegt: %.2f",ergebnis);

}
