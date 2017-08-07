#include <stdio.h>
#include <stdlib.h>

int main()
{
    int zeile,spalte,jahr,monat,tag,wochentag;

    printf("Berechnung des Wochentages anhand des Datums\n\n");

    printf("Datum (tt.mm.jjjj): ");
    scanf("%d.%d.%d",&tag,&monat,&jahr);

    /* Hilfsfeld fuer die Berechnung des Datums */
    int schluessel[28][12] =
      {{4, 0, 0, 3, 5, 1, 3, 6, 2, 4, 0, 2},
       {5, 1, 1, 4, 6, 2, 4, 0, 3, 5, 1, 3},
       {6, 2, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4},
       {0, 3, 4, 0, 2, 5, 0, 3, 6, 1, 4, 6},
       {2, 5, 5, 1, 3, 6, 1, 4, 0, 2, 5, 0},
       {3, 6, 6, 2, 4, 0, 2, 5, 1, 3, 6, 1},
       {4, 0, 0, 3, 5, 1, 3, 6, 2, 4, 0, 2},
       {5, 1, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4},
       {0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5},
       {1, 4, 4, 0, 2, 5, 0, 3, 6, 1, 4, 6},
       {2, 5, 5, 1, 3, 6, 1, 4, 0, 2, 5, 0},
       {3, 6, 0, 3, 5, 1, 3, 6, 2, 4, 0, 2},
       {5, 1, 1, 4, 6, 2, 4, 0, 3, 5, 1, 3},
       {6, 2, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4},
       {0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5},
       {1, 4, 5, 1, 3, 6, 1, 4, 0, 2, 5, 0},
       {3, 6, 6, 2, 4, 0, 2, 5, 1, 3, 6, 1},
       {4, 0, 0, 3, 5, 1, 3, 6, 2, 4, 0, 2},
       {5, 1, 1, 4, 6, 2, 4, 0, 3, 5, 1, 3},
       {6, 2, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5},
       {1, 4, 4, 0, 2, 5, 0, 3, 6, 1, 4, 6},
       {2, 5, 5, 1, 3, 6, 1, 4, 0, 2, 5, 0},
       {3, 6, 6, 2, 4, 0, 2, 5, 1, 3, 6, 1},
       {4, 0, 1, 4, 6, 2, 4, 0, 3, 5, 1, 3},
       {6, 2, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4},
       {0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5},
       {1, 4, 4, 0, 2, 5, 0, 3, 6, 1, 4, 6},
       {2, 5, 6, 2, 4, 0, 2, 5, 1, 3, 6, 1}};

    zeile = (jahr - 1897) % 28;
    spalte = monat - 1;
    wochentag = (schluessel[zeile][spalte] + tag) % 7;

    switch (wochentag)
    {
        case 0: printf("\nDer %d.%d.%d ist ein Samstag.",tag,monat,jahr);break;
        case 1: printf("\nDer %d.%d.%d ist ein Sonntag.",tag,monat,jahr);break;
        case 2: printf("\nDer %d.%d.%d ist ein Montag.",tag,monat,jahr);break;
        case 3: printf("\nDer %d.%d.%d ist ein Dienstag.",tag,monat,jahr);break;
        case 4: printf("\nDer %d.%d.%d ist ein Mittwoch.",tag,monat,jahr);break;
        case 5: printf("\nDer %d.%d.%d ist ein Donnerstag.",tag,monat,jahr);break;
        case 6: printf("\nDer %d.%d.%d ist ein Freitag.",tag,monat,jahr);break;
    }

    return 0;
}
