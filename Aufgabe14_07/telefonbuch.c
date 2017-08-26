#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "telefonbuch.h"

static pKNOTEN head;

/* Loescht alle Knoten der Liste */
void LoescheGanzeListe(void)
{
    /* lokale Variablen */
    pKNOTEN curr,temp;

    /* alle Knoten loeschen */
    curr = head;
    while (curr != NULL)
    {
        temp = curr;
        curr = curr->nachfolger;
        free(temp);
    }

    /* Kopf neu initialisieren */
    head = NULL;
}

/* Fuegt einen Knoten am Anfang der Liste ein */
void FuegeKnotenAmAnfangEin(char *name, char *telefon)
{
    /* lokale Variablen */
    pKNOTEN curr;

    /* neuen Knoten anlegen */
    curr = malloc(sizeof(KNOTEN));
    if  (curr == NULL)
    {
        printf("\nReservierung eines Knotens klappte nicht");
        exit(99);
    }

    /* Daten in Knoten kopieren */
    strcpy(curr->name,name);
    curr->name[19] = '/0';
    strcpy(curr->telefon,telefon);
    curr->telefon[14] = '/0';

    /* Knoten am Anfang der Liste einfuegen */
    if (head == NULL)
    {
        head = curr;
        head->nachfolger = NULL;
    } else
    {
        curr->nachfolger = head;
        head = curr;
    }
}

/* Loescht der ersten Knoten in der Liste */
void LoescheKnotenAmAnfang(void)
{
    /* lokale Variablen */
    pKNOTEN temp;

    temp = head;
    head = head->nachfolger;
    free(temp);
}

/* Gibt die Daten des ersten Knoten in der Liste aus */
void GibKnotenAmAnfangAus(void)
{
    printf("\n%s - %s",head->name,head->telefon);
}

/* Gibt die Daten aller Knoten in der Liste aus */
void GibAlleKnotenAus(void)
{
    /* lokale Variablen */
    pKNOTEN curr = head;

    while (curr != NULL)
    {
    printf("\n%s - %s",curr->name,curr->telefon);
    curr = curr->nachfolger;
    }
}

/* Ermittelt die Anzahl der Knoten in der Liste */
unsigned int ErmittleAnzahlDerKnoten(void)
{
    /* lokale Variablen */
    unsigned int anzahl = 0;;
    pKNOTEN curr;

    /* Anzahl ermitteln */
    curr = head;
    while (curr != NULL)
    {
        anzahl++;
        curr = curr->nachfolger;
    }

    /* Kontenanzahl zurueckgeben */
    return anzahl;
}

/* Gibt die Daten des/der Knoten mit dem uebergebenen Namen aus */
void GibKnotenMitNamenAus(char *name)
{
    /* lokale Variablen */
    pKNOTEN curr = head;

    /* Telefonbucheintrag suchen */
    while ((curr != NULL) && (strcmp(curr->name,name)!=0))
    {
        curr = curr->nachfolger;
    }

    /* Ausgabe */
    if ((curr != NULL) && (strcmp(curr->name,name)==0))
    {
        printf("\n%s - %s",curr->name,curr->telefon);
    } else
    {
        printf("Eintrag mit dem Namen %s konnte nicht gefunden werden.",name);
    }
}

/* Loescht alle Knoten mit dem uebergenenen Namen */
void LoescheKnotenMitNamen(char *name)
{
    /* lokale Variablen */
    pKNOTEN curr = head, temp;

    /* Telefonbucheintrag suchen */
    while ((curr != NULL) && (strcmp(curr->name,name)!=0))
    {
        curr = curr->nachfolger;
    }

    /* Knoten loeschen */
    if ((curr != NULL) && (strcmp(curr->name,name)==0))
    {
        temp = curr;
        curr = curr->nachfolger;
        free(temp);
    } else
    {
        printf("Eintrag mit dem Namen %s konnte nicht gefunden werden.",name);
    }
}

/* Fuegt einen Knoten sortiert in die Liste ein */
void FuegeKnotenSortiertEin(char *name, char *telefon)
{
    /* lokale Variablen */
    pKNOTEN curr = head, temp;

    /* Telefonbucheintrag suchen */
    while ((curr != NULL) && (strcmp(curr->name,name)<0))
    {
        curr = curr->nachfolger;
    }

    /* Knoten einfuegen */
    temp = malloc(sizeof(KNOTEN));
    if (temp == NULL)
    {
        printf("\nReservierung eines Knotens klappte nicht");
        exit(99);
    }

    /* Daten in Knoten kopieren */
    strcpy(temp->name,name);
    temp->name[19] = '/0';
    strcpy(temp->telefon,telefon);
    temp->telefon[14] = '/0';

    /* Knoten einfuegen */
    temp->nachfolger = curr->nachfolger;
    curr->nachfolger = temp;
}
