#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CLRSCR {printf("\n\n\n\n\n\n\n\
                \n\n\n\n\n\n\n\n\n\n\n\
                \n\n\n\n\n\n\n\n\n\n\n\n");}

// Typdefintionen
typedef struct
{
    char name[15];
    char vorname[15];
    int  semester;
    long matrikelnr;
} STUDENTEN;

// globale Variablen
STUDENTEN studenten[50];
unsigned int anzahlStudenten = 0;

// Prototypen
void studentAnlegen(void);
void studentenAuflisten(void);
void studentSuchen(void);

int main()
{
    unsigned int auswahl = 0;

    while (auswahl != 4)
    {
        printf("Studentenverwaltung\n\n");
        printf("1 - Neuen Studenten anlegen\n");
        printf("2 - Alle Studenten auflisten\n");
        printf("3 - Student suchen\n");
        printf("4 - Programm beenden\n");

        printf("\nAuswahl (1, 2, 3 oder 4): ");+
        scanf("%u",&auswahl);

        switch (auswahl)
        {
            case 1: studentAnlegen(); break;
            case 2: studentenAuflisten(); break;
            case 3: studentSuchen(); break;
            case 4: break;
            default: printf("Keine gueltige Eingabe");
        }
    }
    return 0;
}

void studentAnlegen(void)
{
    CLRSCR;
    printf("Student anlegen\n\n");
    printf("Name: ");
    scanf("%s",studenten[anzahlStudenten].name);
    printf("Vorname: ");
    scanf("%s",studenten[anzahlStudenten].vorname);
    printf("Semester: ");
    scanf("%d",&studenten[anzahlStudenten].semester);
    printf("Matrikelnummer: ");
    scanf("%ld",&studenten[anzahlStudenten].matrikelnr);
    anzahlStudenten++;
    CLRSCR;
}

void studentenAuflisten(void)
{
    int i;

    CLRSCR;
    printf("Name-Vorname-Semester-Matrikelnummer\n");
    for (i = 0; i<anzahlStudenten; i++)
    {
        printf("%s-",studenten[i].name);
        printf("%s-",studenten[i].vorname);
        printf("%d-",studenten[i].semester);
        printf("%ld\n",studenten[i].matrikelnr);
    }
    getchar();getchar();
    CLRSCR;
}

void studentSuchen(void)
{
    int auswahl,semester,i;
    long matrikelnr;
    char name[15];

    CLRSCR;
    printf("Suchkriterien:\n");
    printf("1 - Name\n");
    printf("2 - Semester\n");
    printf("3 - Matrikelnummer\n");
    printf("Auswahl (Nummer): ");
    scanf("%d",&auswahl);

    switch (auswahl)
    {
    case 1:
        printf("Name: ");
        scanf("%s",name);
        printf("\nName-Vorname-Semester-Matrikelnummer\n");
        for (i = 0; i<anzahlStudenten; i++)
        {
            if (strcmp(studenten[i].name,name)==0)
            {
            printf("%s-",studenten[i].name);
            printf("%s-",studenten[i].vorname);
            printf("%d-",studenten[i].semester);
            printf("%ld\n",studenten[i].matrikelnr);
            }
        }
        break;
    case 2:
        printf("Semester: ");
        scanf("%d",&semester);
        printf("\nName-Vorname-Semester-Matrikelnummer\n");
        for (i = 0; i<anzahlStudenten; i++)
        {
            if (studenten[i].semester == semester)
            {
            printf("%s-",studenten[i].name);
            printf("%s-",studenten[i].vorname);
            printf("%d-",studenten[i].semester);
            printf("%ld\n",studenten[i].matrikelnr);
            }
        }
        break;
    case 3:
        printf("Matrikelnummer: ");
        scanf("%ld",&matrikelnr);
        printf("\nName-Vorname-Semester-Matrikelnummer\n");
        for (i = 0; i<anzahlStudenten; i++)
        {
            if (studenten[i].matrikelnr == matrikelnr)
            {
            printf("%s-",studenten[i].name);
            printf("%s-",studenten[i].vorname);
            printf("%d-",studenten[i].semester);
            printf("%ld\n",studenten[i].matrikelnr);
            }
        }
        break;
    default: printf("Abbruch! Falsche Auswahl!");
    }
    getchar();getchar();
    CLRSCR;
}
