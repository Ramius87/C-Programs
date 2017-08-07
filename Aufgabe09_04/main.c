#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    struct person
    {
        char name[10];
        char vorname[10];
        unsigned int alter;
    };

    typedef struct personal
    {
        char name[10];
        char vorname[10];
        unsigned int persnr;
    } PERSONAL;

    struct person person_1;
    PERSONAL personal_1;

    printf("Name: ");
    scanf("%s",person_1.name);
    printf("Vorname: ");
    scanf("%s",person_1.vorname);
    printf("Alter: ");
    scanf("%u",&person_1.alter);

    strcpy(personal_1.name,person_1.name);
    strcpy(personal_1.vorname,person_1.vorname);

    printf("Personalnummer: ");
    scanf("%u",&personal_1.persnr);

    printf("\nName: %s", personal_1.name);
    printf("\nVorname: %s", personal_1.vorname);
    printf("\nAlter: %u", person_1.alter);
    printf("\nPersonalnummer: %u", personal_1.persnr);


    return 0;
}
