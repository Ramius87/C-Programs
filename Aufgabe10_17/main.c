#include <stdio.h>
#include <stdlib.h>

int main()
{
    int max_zeilen = 10, max_spalten = 10, matrix[max_zeilen][max_spalten];
    int zeile, spalte, *zeiger;

    // Matrix initialisieren
    for (zeile=0; zeile<max_zeilen; zeile++)
    {
        for (spalte=0; spalte<max_spalten; spalte++)
        {
            zeiger = (int*) matrix + zeile * max_spalten + spalte;
            *zeiger = spalte * 10 + zeile;
        }
    }

    // Matrix ausgeben
    for (zeile=0; zeile<max_zeilen; zeile++)
    {
        for (spalte=0; spalte<max_spalten; spalte++)
        {
            zeiger = (int*) matrix + zeile * max_spalten + spalte;
            printf("-%02d-",*zeiger);
        }
        printf("\n");
    }

    return 0;
}
