#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aktenstapel.h"

/* Makros definieren */
#define PAUSE {printf("\nRETURN!\n"); fflush(stdin); getchar();}

int main (void)
{
    /* Lokale Variablen definieren */
    long nummer;
    long aktennummer;
    char zeichen[5];
    char bearbeiter[30];

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 14-09, Aktenstapel ------------------------\n\n");
    printf("\nDas Programm realisiert einen Aktenstapel als einfach\n");
    printf("verkettete Liste.\n");

    /* Lege neue Akten auf den Stapel */
    printf("\nGeben Sie Aktennummer (Typ long), Aktenzeichen (4 Zeichen ");
    printf("ohne\nBlanks und Sachbearbeiter (29 Zeichen ohne Blanks) der ");
    printf("Akten an,\ndie auf den Stapel gelegt werden. Brechen Sie die ");
    printf("Eingabe mit\n-1 als Aktennummer ab.\n");
    do
    {
        /* Frage nach dem neuen Element */
        printf("\nWie lautet die Aktennummer: ");
        scanf("%ld", &nummer);
        /* Wenn nicht die Eingabe nicht abgebrochen wurde */
        if (nummer != -1)
        {
            /* Frage den Rest der Daten ab */
            printf("Wie lautet das Aktenzeichen: ");
			scanf("%s", zeichen);
            printf("Wie heisst der Sachbearbeiter: ");
			scanf("%s", bearbeiter);
            /* Schiebe diese Akte auf den Stapel */
            push(nummer, zeichen, bearbeiter);
        }
    }
    while (nummer != -1);

    /* Hole Akten vom Stapel, bis dieser leer ist */
    printf("\nIch hole die Akten alle wieder vom Stapel:\n");
    while(Anzahl() > 0)
    {
        pop(&aktennummer, zeichen, bearbeiter);
        printf("Nummer: %07ld, ", aktennummer);
        printf("Zeichen: %5s, ", zeichen);
        printf("Bearbeiter: %s\n", bearbeiter);
    }
    printf("\n\n");
    PAUSE;

    return 0;
}
