#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned int fibrek(unsigned int zahl)
{
    if (zahl == 0)
        return 0;
    else if (zahl <= 2)
        return 1;
    else
        return fibrek(zahl-2) + fibrek(zahl-1);
}

unsigned int fibiter(unsigned int zahl)
{
    // lokale Variablen
    unsigned int i, ergebnis, fib1, fib2;

    fib1 = 0;
    fib2 = 1;

    for (i=1;i<zahl;++i)
    {
        ergebnis = fib1 + fib2;
        fib1 = fib2;
        fib2 = ergebnis;
    }

    return ergebnis;
}

int main()
{
    //lokale Variablen
    long start, ende;
    double zeit;

    printf("Fibonacci-Zahlen\n");

    printf("\nRekursiv:");
    time(&start);
    printf("\nFibonacci von 35: %u",fibrek(35));
    printf("\nFibonacci von 40: %u",fibrek(40));
    time(&ende);
    zeit = difftime(ende, start);
    printf("\nBenoetigte Zeit: %lf", zeit);

    printf("\n\nIterativ:");
    time(&start);
    printf("\nFibonacci von 35: %u",fibiter(35));
    printf("\nFibonacci von 40: %u",fibiter(40));
    time(&ende);
    zeit = difftime(ende, start);
    printf("\nBenoetigte Zeit: %lf", zeit);


    return 0;
}
