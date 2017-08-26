#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "telefonbuch.h"

/* Makros */
#define PAUSE {printf("\nRETURN!\n"); fflush(stdin); getchar();}

/* Prototypen */
void Eingabe(unsigned int sortiert);

int main (void)
{
    /* Lokale Variablen definieren */
    char wahl;
    char name[MAXZEICHEN];

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 14-07, Telefonbuch I ----------------------\n\n");
    printf("\nDas Programm realisiert ein Telefonbuch als einfach\n");
    printf("verkettete Liste.\n");
    printf("Alle Eingaben duerfen maximal 79 Zeichen lang sein und\nduerfen ");
    printf("kein Blank enthalten.\n\n");

    /* Unterscheidung zwischen sortierter und unsortierter Liste */
    printf("Wollen Sie eine sortierte Liste? Geben Sie j oder n ein: ");
    scanf("%c", &wahl);
    printf("\n\n");
    if (wahl == 'n')
        Eingabe(0);
    else
        Eingabe(1);

    /* Anzeigen des ersten Knotens */
    printf("\n\nDer erste Knoten ist:\n");
    GibKnotenAmAnfangAus();

    /* Loeschen des ersten Knotens und anzeigen des neuen ersten Knotens */
    LoescheKnotenAmAnfang();
    printf("\nIch habe den ersten Knoten geloescht. Der neue erste Knoten");
    printf(" ist:\n");
    GibKnotenAmAnfangAus();

    /* Anzeigen der ganzen Liste */
    printf("\nDie ganze Liste:\n");
    GibAlleKnotenAus();

    /* Anzahl der Knoten in der Liste ermitteln */
    printf("\nEs sind %u Knoten in der Liste.\n", ErmittleAnzahlDerKnoten());

    /* Anzeigen eines bestimmten Knotens */
    printf("\nGeben Sie den Namen der Knoten an, den ich anzeigen soll:\n");
    printf("Name: ");
    scanf("%s", name);
    GibKnotenMitNamenAus(name);

    /* Loeschen eines bestimmten Knotens */
    printf("\nGeben Sie den Namen der Knoten an, den ich loeschen soll:\n");
    printf("Name: ");
    scanf("%s", name);
    LoescheKnotenMitNamen(name);

    /* Anzeigen der ganzen Liste */
    printf("\nDie ganze Liste ist nun:\n");
    GibAlleKnotenAus();

    /* Gesamte Liste loeschen und die Anzahl der Knoten ermitteln */
    LoescheGanzeListe();
    printf("\nIch habe die gesamte Liste geloescht. Es sind");
    printf("\nnun %u Knoten in der Liste.\n", ErmittleAnzahlDerKnoten());
    PAUSE;

    return 0;
}

void Eingabe(unsigned int sortiert)
{
    /* Lokale Variablen definieren */
    unsigned int nummer;
    char name[MAXZEICHEN];
    char telefon[MAXZEICHEN];

    /* Eingabe der Daten */
    printf("Bitte geben Sie die Daten von bis zu 10 Personen an. Brechen Sie");
    printf(" die Eingabe\nmit einem * als Namen oder als Telefonnummer");
    printf(" ab.\n\n");

    /* Bis zu 10 Personen koennen eingegeben werden */
    for (nummer = 1; nummer <= 10; nummer++)
    {
        printf("\nBitte geben Sie Daten der %u. Person ein:\n", nummer);

        /* Namen abfragen */
        printf("Name: ");
        scanf("%s", name);
        /* Wenn ein * als Abbruch eingegeben wurde, breche Schleife ab */
        if (strcmp(name, "*") == 0)
            break;
        /* Telefonnummer abfragen */
        printf("Telefon: ");
        scanf("%s", telefon);
        /* Wenn ein * als Abbruch eingegeben wurde, breche Schleife ab */
        if (strcmp(telefon, "*") == 0)
            break;
        /* Fuege Knoten sortiert oder unsortiert in die Liste ein, je nach dem
           uebergebenen Parameter */
        if (sortiert)
            FuegeKnotenSortiertEin(name, telefon);
        else
            FuegeKnotenAmAnfangEin(name, telefon);
    }
}
