#include <stdio.h>
#include <stdlib.h>

#define FAKTOR 25173UL
#define INCR 13849UL
#define MODULO 65536UL

/* Prototypen */
unsigned int Zufallszahl(void);

int main()
{
    /* lokale Variablen */
    int i, anzahl;

    /* Header */
    printf("Pseudozufallszahlengenerator\n\n");

    printf("Wieviele Zufallszahlen sollen generiert werden? ");
    scanf("%u",&anzahl);

    for (i=1; i<=anzahl; i++)
    {
        printf("\n%d.Zufallszahl: %u",i,Zufallszahl());
    }

    return 0;
}

unsigned int Zufallszahl(void)
{
    /* lokale Variablen */
    static unsigned int zufall = 17;

    return zufall = (FAKTOR * zufall + INCR) % MODULO;
}
