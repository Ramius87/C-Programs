#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "telefonbuch.h"

static pKNOTEN root;

/* Fuegt einen Knoten in den binaeren Baum ein */
void FuegeKnotenEin(char *name, char *telefon)
{
    /* lokale Variablen */
    pKNOTEN link, curr;

    /* Knoten anlegen */
    link = (pKNOTEN)malloc(sizeof(KNOTEN));
    if (link == NULL)
    {
        printf("Es konnte kein neuer Knoten im Heap angelegt werden.");
        exit(99);
    }

    /* Knoten mit Daten fuellen */
    strcpy(link->name,name);
    strcpy(link->telefon,telefon);
    link->links = link->rechts = NULL;

    /* Falls erster Knoten*/
    if (root == NULL)
    {
        root = link;
        return;
    }

    /* Einfuegestelle suchen */
    curr = root;
    while (curr != NULL)
    {
        if (strcmp(link->name,curr->name)<=0)
        {
            if (curr->links == NULL)
            {
                curr->links = link;
                break;
            } else
            {
                curr = curr->links;
            }
        } else
        {
            if (curr->rechts == NULL)
            {
                curr->rechts = link;
                break;
            } else
            {
                curr = curr->rechts;
            }
        }
    }
}

static void Praeorder(pKNOTEN wurzel)
{
    /* Wenn der Baum nicht leer ist gib seinen Inhalt aus */
    if (wurzel != NULL)
    {
        printf("Name: %-25s    ", wurzel->name);
        printf("Telefonnummer: %-25s\n", wurzel->telefon);
        Praeorder(wurzel->links);
        Praeorder(wurzel->rechts);
    }
}

static void Inorder(pKNOTEN wurzel)
{
    /* Wenn der Baum nicht leer ist gib seinen Inhalt aus */
    if (wurzel != NULL)
    {
        Inorder(wurzel->links);
        printf("Name: %-25s    ", wurzel->name);
        printf("Telefonnummer: %-25s\n", wurzel->telefon);
        Inorder(wurzel->rechts);
    }
}

static void Postorder(pKNOTEN wurzel)
{
    /* Wenn der Baum nicht leer ist gib seinen Inhalt aus */
    if (wurzel != NULL)
    {
        Postorder(wurzel->links);
        Postorder(wurzel->rechts);
        printf("Name: %-25s    ", wurzel->name);
        printf("Telefonnummer: %-25s\n", wurzel->telefon);
    }
}

/* Gibt die Daten des Baums aus */
void AusgabePraeorder(void)
{
    Praeorder(root);
}

void AusgabeInorder(void)
{
    Inorder(root);
}

void AusgabePostorder(void)
{
    Postorder(root);
}
