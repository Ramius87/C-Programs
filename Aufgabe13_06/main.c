#include <stdio.h>
#include <stdlib.h>

/* Prototypen */
extern void SetSeed(unsigned int seed);
extern unsigned int Random(void);

int main()
{
    /* lokale Variablen */
    int i,anzahl;
    unsigned int seed, zufallszahl;

    /* Header */
    printf("Pseudozufallszahlengenerator in mehreren Modulen\n\n");

    /* Saat festlegen */
    printf("Bitte Saat fuer Zufallszahlen eingeben: ");
    scanf("%u",&seed);
    SetSeed(seed);

    /* Anzahl Zufallszahlen festlegen */
    printf("\nWieviele Zufallszahlen sollen generiert werden? ");
    scanf("%d",&anzahl);

    /* Zufallszahlen ausgeben */
    for (i=1; i<=anzahl; i++)
    {
        zufallszahl = Random();
        printf("\n%u.Zufallszahl: %u",i,zufallszahl);
    }

    return 0;
}
