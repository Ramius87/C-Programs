#include <stdio.h>
#include <stdlib.h>

#define MAX_VEKTOR 100

// Typdefinitionen
typedef struct
{
    char name[20];
    char vorname[20];
    int alter;
} PERSON;

// globale Variablen
PERSON personen[MAX_VEKTOR];

int main()
{
    // lokale Variablen
    PERSON *person;
    int anzahl, i = 0;

    printf("Personenvektor\n\n");
    printf("Wieviele Personen sollen angelegt werden? ");
    scanf("%d",&anzahl);

    while (i < anzahl)
    {
        // Zeiger setzen
        person = personen + i;

        printf("\nPerson %d\n",i+1);
        printf("Name: ");
        scanf("%s",person->name);
        printf("Vorname: ");
        scanf("%s",person->vorname);
        printf("Alter: ");
        scanf("%d",&(person->alter));

        // Zaehler inkrementieren
        i++;
    }

    for (i=0; i<anzahl; i++)
    {
        person = personen+i;
        printf("\n%s %s - %d Jahre",person->vorname,person->name,person->alter);
    }

    return 0;
}
