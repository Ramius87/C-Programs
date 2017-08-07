#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    //lokale Variablen
    char name[10];
    char anrede[5];
    char taetigkeit[] = " geht zur Arbeit.\n";
    char satz[50];

    printf("String - Basteleien\n\n");

    printf("Bitte geben Sie Ihren Namen ein: ");
    scanf("%s",name);

    printf("Bitte geben Sie die Anrede (Herr/Frau) ein: ");
    scanf("%s",anrede);

    if (strcmp(anrede,"Herr")==0)
        printf("%s %s ist maennlichen Geschlechts.\n",anrede,name);
    else
        printf("%s %s ist weiblichen Geschlechts.\n",anrede,name);


    strcpy(satz,anrede);
    strcat(satz," ");
    strcat(satz,name);
    strcat(satz,taetigkeit);
    printf(satz);

    printf("\nLaenge des letzten Satzes: %d Zeichen",strlen(satz));

    return 0;
}
