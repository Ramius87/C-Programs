#include <stdio.h>
#include <stdlib.h>

int main()
{
    // lokale Variablen
    FILE *fp;
    char dateiname[30], zeile[30];

    printf("Datei einlesen und anzeigen\n\n");

    printf("Bitte Dateinamen eingeben: ");
    scanf("%s",dateiname);

    fp = fopen(dateiname,"r");
    if (fp == NULL)
    {
        printf("\nAngegebene Datei konnte nicht geoeffnet werden.");
        printf("\nProgramm wird beendet");
        exit(99);
    }

    while (fgets(zeile,30,fp))
    {
        printf("%s",zeile);
    }

    fclose(fp);
    return 0;
}
