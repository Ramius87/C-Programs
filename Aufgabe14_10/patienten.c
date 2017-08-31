#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "patienten.h"

static pKNOTEN first, last;

/* Schiebt einen Knoten in die Schlange */
void rear(char *name, char *beschwerden)
{
    /* lokale Variablen */
    pKNOTEN link;

    /* neuen Knoten anlegen */
    link = (pKNOTEN)malloc(sizeof(KNOTEN));
    if(link == NULL)
    {
        printf("Es konnte kein neuer Knoten angelegt werden.");
        exit(99);
    }

    /* Knoten Daten zuweisen */
    strcpy(link->name,name);
    strcpy(link->beschwerden,beschwerden);
    link->nachfolger = NULL;

    /* Knoten einfuegen */
    if (first == NULL)
    {
        first = last = link;
    } else
    {
        last->nachfolger = link;
        last = link;
    }
}

/* Nimmt den ersten (vordersten) Knoten aus der Schlange und liefert die Daten*/
boolean front(char *name, char *beschwerden)
{
    /* lokale Variablen */
    pKNOTEN link;

    if (first == NULL)
        return FALSE;

    /* Daten ausgeben */
    strcpy(name,first->name);
    strcpy(beschwerden,first->beschwerden);

    /* Knoten loeschen */
    link = first;
    first = first->nachfolger;
    free(link);

    return TRUE;
    return TRUE;
}

/* Liefert die Daten des ersten Knotens in der Schlange ohne ihn zu loeschen */
boolean next(char *name, char *beschwerden)
{
    if (first == NULL)
        return FALSE;

    /* Daten ausgeben */
    strcpy(name,first->name);
    strcpy(beschwerden,first->beschwerden);

    return TRUE;
}

/* Liefert die Anzahl der Knoten in der Schlange */
unsigned long Anzahl(void)
{
    /* lokale Variablen */
    pKNOTEN link;
    unsigned long anzahl = 0;

    link = first;
    while (link != NULL)
    {
        link = link->nachfolger;
        anzahl++;
    }
    return anzahl;
}
