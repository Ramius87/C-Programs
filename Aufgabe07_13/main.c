#include <stdio.h>

#define PAUSE {printf("\nRETURN!\n"); fflush(stdin); getchar();}

void pyramiden_zeile(int zahl, int i);
void pyramiden_zeile_binaer(int i);

int main(void)
{
    /* lokale Variablen */
    int anzahl, i, j;

    /* Anweisungen */

    printf("Das Programm zeichnet eine Zahlenpyramide.\n\n");

    /* Abfrage der Werte, bis ein gueltiger Wert eingegeben wurde */
    do
    {
		printf("Wieviele Zeilen soll die Pyramide hoch sein (1-9) ? ");
        scanf("%d", &anzahl);
    }
    while ((anzahl < 1) || (anzahl > 9));
    printf("\n\n");

    /* Hoehe des Dreiecks */
    for (i = 1; i <= anzahl; i++)
    {
        /* Bildschirmkosmetik */
        for (j = 20; j > i; j--)
            putchar(' ');
        pyramiden_zeile(1,i);   /* Aufruf der Funktion */
        printf("\n");         /* Zeilenumbruch fuer naechste "Etage" */
    }
    printf("\n\n");

    /* Binaerdreieck */
    for (i = 1; i <= anzahl; i++)
    {
        /* Bildschirmkosmetik */
        for (j = 20; j > i; j--)
            putchar(' ');
        pyramiden_zeile_binaer(i);   /* Aufruf der Funktion */
        printf("\n");         /* Zeilenumbruch fuer naechste "Etage" */
    }
    printf("\n\n");

    PAUSE;
    return 0;
}

/* Funktion: pyramiden_zeile
   zeichnet eine Zeile der Pyramide */
void pyramiden_zeile(int zahl, int i)
{
    /* Anweisungen */
    printf("%d", zahl);            /* Ausgabe links */
    if (zahl < i)
        pyramiden_zeile(zahl + 1,i);  /* rekursiver Aufruf */
    if (zahl != i)
          printf("%d", zahl);        /* Ausgabe rechts */
}

void pyramiden_zeile_binaer(int i)
{
    int l;
    /* Anweisungen */
    for (l=1; l<=i;l++)
    {
        if (l == 1 || l%2==1)
            printf("1");
        else
            printf("0");
    }
    l--;
    while (--l>0)
    {
        if (l == 1 || l%2==1)
            printf("1");
        else
            printf("0");
    }
}

