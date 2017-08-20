#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Typdefinitionen
typedef struct
{
    unsigned int nummer;
    char name[21];
    char vorname[21];
} PERSON;

int main()
{
    //lokale Variablen
    PERSON personen[5];
    char dateiname[] = "personen.txt";
    FILE *fp;
    int i,anzahl;

    // Header
    printf("Personen-Textdatei abspeichern und auslesen\n\n");

    printf("Bitte die Anzahl der Personen (max. 5) festlegen: ");
    scanf("%d",&anzahl);

    // Daten einlesen
    for (i=0;i<anzahl;i++)
    {
        printf("\nBitte Daten von Person %d angeben:\n",i+1);
        printf("Personalnummer: ");
        scanf("%u",&personen[i].nummer);
        printf("Name: ");
        scanf("%s",personen[i].name);
        printf("Vorname: ");
        scanf("%s",personen[i].vorname);
    }

    // Datei oeffnen & Personenvektorschreiben
    printf("\nDatei wird nun angelegt");
    fp = fopen(dateiname,"w+");
    printf("\nPersonendaten werden in die Datei geschrieben");
    for (i=0;i<anzahl;i++)
    {
        fprintf(fp,"%u %s %s\n",personen[i].nummer,
                personen[i].name,personen[i].vorname);
    }
    printf("\nDatei wird nun geschlossen");
    fclose(fp);

    // Personenvektor reinitialisieren
    printf("\n\nPersonenvektor wird reinitialisiert");
    for (i=0;i<anzahl;i++)
    {
        personen[i].nummer = 0;
        strcpy(personen[i].name,"");
        strcpy(personen[i].vorname,"");
    }

    // Datei einlesen und Personenvektor fuellen
    printf("\n\nDatei %s wird nun zum Lesen geoeffnet",dateiname);
    fp = fopen(dateiname,"r");
    if (fp == NULL)
    {
        printf("Datei %s laesst sich nicht oeffnen\n",dateiname);
        printf("Programm wird beendet");
        exit(99);
    }
    printf("\nPersonendaten werden eingelesen");
    i=0;
    while (fscanf(fp,"%u %s %s\n",&personen[i].nummer,
                personen[i].name,personen[i].vorname)!=EOF)
    {
        i++;
    }
    printf("\nDatei wird nun geschlossen");
    fclose(fp);

    printf("\n\nPersonendaten:\n");
    printf("Personalnummer-Name-Vorname\n");
    for (i=0;i<anzahl;i++)
    {
        printf("%u-%s-%s\n",personen[i].nummer,
                personen[i].name,personen[i].vorname);
    }

    return 0;
}
