#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // lokale Variablen
    FILE *fp;
    char zeile[40];

    printf("Text in Datei schreiben\n\n");

    // Datei oeffnen
    fp = fopen("text.txt","w+");
    if (fp == NULL)
    {
        printf("Datei konnte nicht zum Schreiben geoeffnet werden.");
        exit(99);
    }

    printf("Bitte Text eingeben und mit RETURN bestaetigen\n");
    printf("Beenden mit *\n");

    do
    {
        // Zeile einlesen
        gets(zeile);
        // Zeile schreiben
        fputs(zeile,fp);
        // Zeile beenden
        fputc('\n',fp);
    }
    while (strcmp(zeile,"*"));

    // Datei schliessen
    fclose(fp);

    return 0;
}
