#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aktenstapel.h"

static pKNOTEN oben;

/* Schiebt ein Element auf den Stapel */
void push(unsigned long nummer, char *zeichen, char *bearbeiter)
{
    /* lokale Variablen */
    pKNOTEN link;

    /* Knoten anlegen */
    link = (pKNOTEN)malloc(sizeof(KNOTEN));
    if (link == NULL)
    {
        printf("Ein neuer Knoten konnte nicht angelegte werden.");
        exit(99);
    }
    link->aktennummer = nummer;
    strcpy(link->aktenzeichen,zeichen);
    strcpy(link->sachbearbeiter,bearbeiter);

    /* Knoten in Stapel einfuegen */
    link->nachfolger = oben;
    oben = link;
}

/* Nimmt das erste Element von dem Stapel und liefert die Daten */
boolean pop(unsigned long *nummer, char *zeichen, char *bearbeiter)
{
    /* lokale Variablen */
    pKNOTEN temp;

    if (oben != NULL)
    {
        /* Knotendaten ausgeben */
        *nummer = oben->aktennummer;
        strcpy(zeichen,oben->aktenzeichen);
        strcpy(bearbeiter,oben->sachbearbeiter);

        /* Knoten loeschen */
        temp = oben;
        oben = oben->nachfolger;
        free(temp);

        return TRUE;
    } else
    {
        return FALSE;
    }
}

/* Liefert die Daten des ersten Elements auf dem Stapel ohne es zu loeschen */
boolean top(unsigned long *nummer, char *zeichen, char *bearbeiter)
{
    if (oben != NULL)
    {
        /* Knotendaten ausgeben */
        *nummer = oben->aktennummer;
        strcpy(zeichen,oben->aktenzeichen);
        strcpy(bearbeiter,oben->sachbearbeiter);

        return TRUE;
    } else
    {
        return FALSE;
    }
}

/* Liefert die Anzahl der Elemente auf dem Stack */
unsigned long Anzahl(void)
{
    /* lokale Variablen */
    unsigned int anzahl = 0;
    pKNOTEN link = oben;

    while (link != NULL)
    {
        anzahl++;
        link = link->nachfolger;
    }
    return anzahl;
}
