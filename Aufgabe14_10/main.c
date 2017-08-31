#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "patienten.h"

int main()
{
    /* Lokale Variablen definieren */
    char name[30];
    char beschwerden[30];

    /* Anweisungen */

    /* Information */
    printf("\nDasProgramm realisiert eine Schlange als einfach verkettete");
    printf(" Liste\n");

    /* Schiebe Daten des Patienten in die Schlange */
    printf("\nGeben Sie die Namen und die Beschwerden (jeweils bis zu ");
    printf("29 Zeichen\nohne Blanks) der Patienten ein, die ");
	 printf("sich an der Rezeption anmelden.\nBrechen Sie die Eingabe mit ");
    printf("einem * als Namen ab.\n");
    do
    {
        /* Frage nach den neuen Daten */
        printf("\nWie lautet der Name des Patienten: ");
		scanf("%s", name);
        /* Wenn nicht die Eingabe nicht abgebrochen wurde */
        if (strcmp(name, "*") != 0)
        {
            /* Frage den Rest des Daten ab */
            printf("Welche Beschwerden hat der Patient: ");
			scanf("%s", beschwerden);
            /* Schiebe diese Daten in die Schlange */
            rear(name, beschwerden);
        }
    }
    while (strcmp(name, "*") != 0);

    /* Hole die Daten aus der Schlange, bis diese leer ist */
    printf("\nIch hole die Daten alle wieder aus der Schlange:\n");
    while(Anzahl() > 0)
    {
        front(name, beschwerden);
        printf("Name: %-25s    Beschwerden: %-25s\n", name, beschwerden);
    }
    printf("\n\n");
    return 0;
}
