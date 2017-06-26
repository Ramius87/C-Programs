#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("--------------- Persoenliche Daten ---------------\n\n");

    char name[20];
    char vorname[20];
    char geburtsdatum[10];
    char geburtsort[20];

    printf("Nachname: ");
    gets(name);
    printf("Vorname: ");
    gets(vorname);
    printf("Geburtsdatum: ");
    gets(geburtsdatum);
    printf("Geburtsort: ");
    gets(geburtsort);

    printf("\n\nNachname: %s", name);
    printf("\n\Vorname: %s", vorname);
    printf("\nGeburtsdatum: %s", geburtsdatum);
    printf("\nGeburtsort: %s", geburtsort);

    printf("\n\nSie heissen %s %s und wurden am %s in %s geboren.",vorname,name,geburtsdatum,geburtsort);

    return 0;
}
