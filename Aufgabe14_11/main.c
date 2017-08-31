#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "telefonbuch.h"

int main()
{
    /* Lokale Variablen definieren */
    char name[30];
    char nummer[30];
    int wahl;

    printf("\nDas Programm realisiert ein Telefonbuch als binaeren Baum.\n");

    /* Eingabe der Telefonnummern */
    printf("\nGeben Sie den Namen und die Telefonnummer ein, die in dem ");
    printf("binaeren Baum\ngespeichert werden soll. Name und Telefonnummer ");
    printf("duerfen maximal 29 Zeichen\nlang sein und duerfen keine Blanks ");
    printf("beinhalten. Brechen Sie die Eingabe\n");
    printf("mit * als Name ab.\n");
    do
    {
        /* Frage nach den Namen */
        printf("\nName: ");
		scanf("%s", name);
        /* Wenn nicht die Eingabe nicht abgebrochen wurde */
        if (strcmp(name, "*") != 0)
        {
            /* Frage den Rest der Daten ab */
            printf("Telefonnummer: ");
			scanf("%s", nummer);
            /* Speicher die Daten im Baum */
            FuegeKnotenEin(name, nummer);
        }
    }
    while (strcmp(name, "*") != 0);

    /* Ausgabe der Daten in gewuenschter Art */
    for (;;)
    {
        /* Menue */
        printf("\n\nIn welcher Reihenfolge sollen die Daten ausgegeben ");
        printf("werden?\n(1) Praeorder\n(2) Inorder\n(3) Postorder\n");
        printf("(4) Programm beenden\n\n> ");
        scanf("%d", &wahl);

        /* Ausgabe */
        switch (wahl)
        {
            case 1: printf("\nPraeorder:\n\n"); AusgabePraeorder();
                    break;
            case 2: printf("\nInorder:\n\n"); AusgabeInorder();
                    break;
            case 3: printf("\nPostorder:\n\n"); AusgabePostorder();
                    break;
            case 4: return 0;
        }
    }
}
